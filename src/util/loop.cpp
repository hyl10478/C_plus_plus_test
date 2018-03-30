/*
 * Copyright C 2017-2027 yatao.fu
 */

#include <unistd.h>
#include <cstring>
#include <pthread.h>
#include "util.hpp"
#include "loop.h"

//uint32_t cpu_num = 0;
//uint32_t cpu_index = 0;
namespace horizon_analysis_server {
loop::loop() : m_lastProTime(0),
               m_pThread(NULL),
               m_stat(THREAD_DEFAULT) {
  m_stat = THREAD_DEFAULT;
  m_gap = THREAD_SLEEP_GAP;

  memset(m_name, 0, MAX_THREAD_NAME_LEN);
  snprintf(m_name, MAX_THREAD_NAME_LEN, "basic_loop");
//  cpu_num = std::thread::hardware_concurrency();
}

loop::~loop() {
  if (NULL == m_pThread) return;
  {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_stat = THREAD_DEAD;
  }

  m_pThread->join();
  delete m_pThread;
  m_pThread = NULL;
}

bool loop::start() {
  std::unique_lock<std::mutex> lock(m_mutex);
  m_stat = THREAD_RUNNING;
  m_pThread = new std::thread(startPro, this);
  return m_pThread != NULL;
}

void loop::stop() {
  if (NULL == m_pThread) {
    return;
  }

  {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_stat = THREAD_DEAD;
  }

  m_pThread->join();
  delete m_pThread;
  m_pThread = NULL;
}

void loop::stopNoWait() {
  if (NULL == m_pThread) {
    return;
  }

  {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_stat = THREAD_DEAD;
  }
}

void loop::wait() {
  if (NULL == m_pThread) {
    return;
  }

  m_pThread->join();

  delete m_pThread;

  m_pThread = NULL;
}

void loop::pause() {
  std::unique_lock<std::mutex> lock(m_mutex);
  m_stat = THREAD_PAUSE;
}

void loop::resume() {
  std::unique_lock<std::mutex> lock(m_mutex);
  m_stat = THREAD_RUNNING;
}


bool loop::isRunning() {
  std::unique_lock<std::mutex> lock(m_mutex);
  return m_stat == THREAD_RUNNING;
}

bool loop::isPause() {
  std::unique_lock<std::mutex> lock(m_mutex);
  return m_stat == THREAD_PAUSE;
}

void loop::nofity() {
  // 如果线程当前在休眠,则唤醒
  std::unique_lock<std::mutex> lock(m_resultLock);
  m_cond.notify_all();
}

THREAD_STATUS loop::status() {
  std::unique_lock<std::mutex> lock(m_mutex);
  return m_stat;
}

// 用来间接创建基于类成员函数的线程
void loop::startPro(void *thr) {
  loop *thread = static_cast<loop *>(thr);

  if (NULL != thread) {

    bool skipWait = false;
    int64_t curr = 0;
    int64_t per = 0;
    int64_t gap = 0;

    while (thread->isRunning() || thread->isPause()) {
      if (!skipWait) {
        curr = getMilliSecond();
        gap = std::max(curr - per, (int64_t )0);
        if (gap > thread->m_gap) {
          gap = thread->m_gap;
        }

        gap = thread->m_gap - gap;

        if (gap > 0) {
          std::unique_lock<std::mutex> lock(thread->m_resultLock);
          thread->m_cond.wait_for(lock, std::chrono::milliseconds(gap));
        }
        per = curr;

      }

      // 如果线程处理返回不需要跳过下次处理,或者线程还有消息要处理,则进行处理
      skipWait = thread->pro();

    }
  }
}
}
