//
// Created by yalin.han on 2017/8/18.
//
#include "BasicTest.h"
#include <string>
#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>


extern const std::string value = "hehe";

extern  const int VARIABLE_FIRST = 112211;



/**
 * 字符串和char
 * string and char test
 */
void BasicTest::test1() {
    /*char *ch = "abcd";              //字符串,以'\0'结尾
    std::string string5 = ch;
    std::cout << strlen(ch) << std::endl;

    char ch1[5] = "efgh";           //字符数组，以'\0'结尾
    std::cout << strlen(ch1) << std::endl;

    std::string string1 = "abcd";
    std::cout << string1.substr(1) << " " << string1.size() << std::endl;
    if (!string1.empty()) {
        std::cout << "false" << std::endl;
    }

    char ch3[] = {'a', 'b', 'c', 'd', '\0'};
    std::cout << strlen(ch3) << std::endl;

    std::string string2 = "aa";
    std::string string3 = "bb";
    std::string string4 = string2 + string3;
    std::cout << string4 << std::endl;

    char *ch5 = "bb";
    char ch6[10];
    strcpy(ch6, ch5);
    strcat(ch6, ch5);
    std::cout << ch6 << std::endl;*/
}

/*
 *%02d test
 *格式
 */
void BasicTest::test2() {
    /*student stu2 = {10003, "wanggang", 'M', {1990, 2, 3}, {1, 2, 3, 4}};
    printf("stu2: %ld %s %c %d/%02d/%02d %03d %04d %d %d\n",
           stu2.id,
           stu2.name,
           stu2.sex,
           stu2.birthday.year,
           stu2.birthday.month,
           stu2.birthday.day,
           stu2.score[0],
           stu2.score[1],
           stu2.score[2],
           stu2.score[3]);*/
}

void BasicTest::test3() {
    /* int i;
     char buffer[256];
     printf("Enter a number: ");
     fgets(buffer, 256, stdin);
     i = atoi(buffer);
     printf("The value entered is %d. Its double is %d.\n", i, i * 2);*/

    char buf[100];
    memset(buf, 65, 50);
    for (int i = 0; i < sizeof(buf) / sizeof(char); ++i) {
        std::cout << buf[i] << std::endl;
    }


    /*int array[100];
    memset(array, 0, sizeof(array));
    for (int i = 0; i < 100; ++i) {
       std::cout<<array[i]<<std::endl;
    }*/
}

void BasicTest::testMap() {
    std::map<std::string, int> map;
    map.insert(std::make_pair("1", 2));
    map.insert(std::make_pair("2", 3));
    map.insert(std::make_pair("3", 4));
    for (auto iter = map.begin(); iter != map.end(); ++iter) {
        std::cout << iter->first << " " << iter->second << std::endl;
    }
    auto ret = map.insert(std::make_pair("1", 5));
    if (!ret.second) {
        std::cout << "failed" << std::endl;
    }

    for (auto iter = map.begin(); iter != map.end(); ++iter) {
        std::cout << iter->first << " " << iter->second << std::endl;
    }

    if (map.find("1") != map.end()) {
        auto iter = map.find("1");
        std::cout << map["1"] << std::endl;
        std::cout << iter->second << std::endl;
        std::cout << map.find("1")->second << std::endl;
    }
}

void BasicTest::testSet() {
    std::set<std::string> set = {"the", "but", "and"};
    if (set.find("the") != set.end()) {                     //find返回一个迭代器
        std::cout << "true" << std::endl;
    }

    if (set.find("hehe") == set.end()) {
        std::cout << "false" << std::endl;
    }
}

void BasicTest::testVector() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter) {
        std::cout << *iter << std::endl;
    }
    std::cout << vec.size() << std::endl;
    printf("*********************\n");
    for (auto iter:vec) {
        std::cout << iter << std::endl;
    }
}

void BasicTest::testMap2() {
    std::map<int, int> test_map;
    test_map.insert(std::make_pair(1, 1));
    test_map.insert(std::make_pair(2, 2));
    test_map.insert(std::make_pair(3, 3));
    test_map.insert(std::make_pair(4, 4));

    for (auto iter = test_map.cbegin(); iter != test_map.end(); ++iter) {
        std::cout << iter->first << " " << iter->second << std::endl;
    }

    for (auto iter:test_map) {
        std::cout << iter.first << std::endl;
    }
}

void BasicTest::testDynamicMem() {
    int *array = new int[100];
    std::shared_ptr<int> ptr(array);
    if (ptr) {
        std::shared_ptr<std::string> pointer(new std::string[100]);
    }
    std::vector<std::string> v1;
    {
        std::vector<std::string> v2 = {"a", "an", "the"};
        for (auto iter = v2.cbegin(); iter != v2.cend(); ++iter) {
            std::cout << *iter << std::endl;
        }
        for (auto iter1:v2) {
            std::cout << iter1 << std::endl;
        }
        v1 = v2;
    }
    for (auto iter:v1) {
        std::cout << iter << std::endl;
    }

}

void BasicTest::testHeap() {
    /* int *array = new int[100]();
     for (int i = 0; i < 100; ++i) {
         std::cout<<array[i]<<std::endl;
     }
     delete[] array;*/


    /* char *array = new char[10];
     memset(array, 97, 10);
     for (int i = 0; i < 10; ++i) {
         std::cout<<array[i]<<std::endl;
     }
     delete[] array;*/

    char *name = new char[32];      //--动态申请内存
    memset(name, 0, sizeof(name));
    strcpy(name, "we are students.");
    std::cout << name << std::endl;
    delete[] name;
}

void BasicTest::testDynamicMem2() {
    int n;
//    char array[n];
//    std::cout<< sizeof(array)<<std::endl;
    std::cout << "aa:" << std::endl;
    std::cin >> n;
    std::cout << "number is :" << n << std::endl;
    char array[n];
    std::cout << sizeof(array) << " " << "hehe" << std::endl;
    /* int len;
     std::cin>>len;
     int array[len];
     std::cout<< "array size:"<<sizeof(array)<<std::endl;*/

}

void Invoke(char *s);

void BasicTest::testFunPtr(void (*callBack)(char *), char *s) {
    callBack(s);
}

void BasicTest::test4() {
    char ch[10] = {0};
    snprintf(ch, sizeof(ch), "jkjjkjkjkjjkjkjkjkjk");
    std::cout << ch << std::endl;
}

void BasicTest::testExtern() {
    std::cout<<this->value1111<<std::endl;
}

