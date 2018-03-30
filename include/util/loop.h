/*
 * Copyright(c) 2016 Horizon Robotics Technologies Co., Ltd. All rights
 * reserved.
 *
 * 基础loop类，定义loop类的基础结构
 *
 * Created by Yatao Fu on Dec 19th, 2016.
 */

#ifndef CUSTOMERANALYSISSERVER_IPC_LOOP_H_
#define CUSTOMERANALYSISSERVER_IPC_LOOP_H_

#include <mutex>
#include <queue>
#include <thread>
#include <condition_variable>

namespace horizon_analysis_server {
#define MAX_THREAD_NAME_LEN 32      // 线程名最大长度
#define THREAD_SLEEP_GAP 30 * 1000  // 线程默认休眠间隔

typedef enum {
  THREAD_DEFAULT = 0,  // 线程初始化
  THREAD_RUNNING = 1,  // 线程正在运行
  THREAD_DEAD = 2,     // 线程已经结束，等待释放资源
  THREAD_PAUSE = 3,    // 线程被暂停
} THREAD_STATUS;

class loop {
public:
  loop();

  // 启动loop
  virtual bool start();

  // 停止loop,会等待当前事物处理完成后才退出
  virtual void stop();

  // 设置线程停止标示，但不阻塞主线层
  virtual void stopNoWait();

  // 阻塞当前线程，等待该线程结束
  virtual void wait();

  // 暂停loop
  virtual void pause();

  // 恢复线程
  virtual void resume();

  virtual THREAD_STATUS status();

  virtual bool isRunning();

  virtual bool isPause();

  virtual ~loop();

  //  结束sleep，直接开始运行
  virtual void nofity();

  int64_t getLastProTime() { return m_lastProTime; }


protected:
  // 主处理函数，必须实现
  // 返回值表示下循环是否跳过休眠, ture: 跳过休眠  false: 需要休眠
  virtual bool pro() = 0;

  char m_name[MAX_THREAD_NAME_LEN];  // 线程名称

  uint32_t m_gap;  // 线程休眠间隔

  int64_t m_lastProTime;  // 线程最后一次处理时间

private:
  // 内用用来启动线程
  static void startPro(void* thr);

  std::thread* m_pThread;

  std::mutex m_mutex;

  THREAD_STATUS m_stat;  // 线程状态

  std::mutex m_resultLock;

  std::condition_variable m_cond;
};
}
#endif  // CUSTOMERANALYSISSERVER_IPC_LOOP_H_
