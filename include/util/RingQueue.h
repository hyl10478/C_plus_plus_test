//
// Created by Minghao Wang on 17-9-26.
// Copyright (c) 2017 Horizon Robotics. All rights reserved.
//

#ifndef CUSTOMERANALYSIS_RINGQUEUE_H
#define CUSTOMERANALYSIS_RINGQUEUE_H

#include <deque>
#include <mutex>
#include <condition_variable>
#include <hobotlog/hobotlog.hpp>

template <typename Dtype>
class RingQueue
{
 public:
  explicit RingQueue(typename std::deque<Dtype>::size_type size) : size_(size) {
    HOBOT_CHECK(size) << "try to construct 0 length ring queue";
  }

  void Push(const Dtype& elem) {
    {
      std::lock_guard<std::mutex> lock(mtx_);
      if (que_.size() == size_)
        que_.pop_front();

      que_.push_back(elem);
    }
    cv_.notify_all();
  }

  Dtype Pop() {
    std::unique_lock<std::mutex> lock(mtx_);
    cv_.wait(lock, [this]{return !que_.empty();});//no empty (true),go on  wait()会去检查这些条件(通过调用所提供的lambda函数)，当条件满足(lambda函数返回true)时返回。如果条件不满足(lambda函数返回false)，wait()函数将解锁互斥量，并且将这个线程(上段提到的处理数据的线程)置于阻塞或等待状态
    auto elem = que_.front();
    que_.pop_front();

    return elem;
  }

  bool empty() {
    std::lock_guard<std::mutex> l(mtx_);
    return que_.empty();
  }
 private:
  const typename std::deque<Dtype>::size_type size_;
  std::deque<Dtype> que_;
  std::mutex mtx_;
  std::condition_variable cv_;
};

#endif //CUSTOMERANALYSIS_RINGQUEUE_H
