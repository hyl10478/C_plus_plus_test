//
// Created by yalin.han on 2017/8/18.
//

#ifndef PRO1_BASICTEST_H
#define PRO1_BASICTEST_H

#include <cstdint>
#include <string>



typedef void (*FP)(char *s);

struct date {
    int year;
    int month;
    int day;
};

struct student {
    long id;
    char name[10];
    char sex;
    date birthday;
    int score[4];
    student(){

    }
};


class BasicTest {
public:
    int value1111 = 66;

    void test1();

    void test2();

    void test3();

    void testMap();

    void testSet();

    void testVector();

    void testMap2();

    void testDynamicMem();

    void testDynamicMem2();

    void testHeap();

    void testFunPtr(void (*callBack)(char *), char *);

    void test4();

    void testExtern();
};


#endif //PRO1_BASICTEST_H
