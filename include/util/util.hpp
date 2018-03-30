/*!
 * Copyright (c) 2017 by Horizon Robotics. All rights reserved.
 * \file common.h
 * \brief
 * \author yatao.fu
 * \date  17-9-21
 */

#ifndef CUSTOMERANALYSISSERVER_IPC_UTIL_H
#define CUSTOMERANALYSISSERVER_IPC_UTIL_H

#include <cstdint>
#include <string>
#include <cmath>
#include <chrono>

namespace horizon_analysis_server {
/**
 *
 * @tparam T float/int/double ....
 * @param t1 point
 * @param t2 range - min
 * @param t3 range - max
 * @return  1 point > range
 *          0 point in range
 *          -1 point < range
 */
template <typename T>
inline int inRange(const T & t1, const T & t2, const T & t3) {
  if (t1 >= t3) return 1;
  if (t1 >= t2 && t1 < t3) return 0;
  return -1;
}

#define MilliSecondByDay (24 * 60 * 60 * 1000)
#define TimeZoneMill (8 * 60 * 60 * 1000)

inline std::string getTimeString() {
  auto tt = std::chrono::system_clock::to_time_t(
      std::chrono::system_clock::now());
  struct tm* ptm = localtime(&tt);
  char date[60] = { 0 };
  sprintf(date, "%d-%02d-%02d_%02d-%02d-%02d", (int) ptm->tm_year + 1900,
          (int) ptm->tm_mon + 1, (int) ptm->tm_mday, (int) ptm->tm_hour,
          (int) ptm->tm_min, (int) ptm->tm_sec);
  return std::string(date);
}

inline std::int64_t getMicroSecond(void) {
  struct timespec ts = {0, 0};
  clock_gettime(CLOCK_REALTIME, &ts);
  return (std::int64_t)ts.tv_sec * 1000000 + ts.tv_nsec / 1000;
}

inline std::int64_t getMilliSecond(void) {
  struct timespec ts = {0, 0};
  clock_gettime(CLOCK_REALTIME, &ts);
  return (std::int64_t)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

inline std::int64_t getSecond(void) {
  struct timespec ts = {0, 0};
  clock_gettime(CLOCK_REALTIME, &ts);
  return (std::int64_t)ts.tv_sec;
}

inline std::int64_t getStartTimeFromGap(int64_t gap) {
  auto  days = getMilliSecond() / MilliSecondByDay;
  return days * MilliSecondByDay + gap - TimeZoneMill;
}










}
#endif  // CUSTOMERANALYSISSERVER_IPC_UTIL_H
