//
// Created by yalin.han on 2017/8/18.
//

#include <cstdio>
#include <ctime>
#include <chrono>
#include <iostream>
#include <zconf.h>
#include "TimeTest.h"

void TimeTest::test() {
    time_t timep;
    time(&timep); /*获取time_t类型的当前时间*/
    printf("time:%d\n", timep);
    struct tm *time2 = localtime(&timep);
    printf("time:%d-%d-%d-%d-%d-%d\n", time2->tm_year + 1900, time2->tm_mon + 1, time2->tm_mday, time2->tm_hour,
           time2->tm_min, time2->tm_sec);
    printf("%s", asctime(gmtime(&timep)));
    printf("%s", ctime(&timep));
}

void TimeTest::test2() {
    time_t time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now()
    );
    std::cout<<time<<std::endl;
    std::cout<<ctime(&time)<<std::endl;
}