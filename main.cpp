#include <iostream>
#include <cstring>
#include <fstream>
#include <bits/unique_ptr.h>
#include <getopt.h>
#include <map>
#include <thread>
#include <vector>
#include <zconf.h>
#include <assert.h>
#include <Person.h>
#include <algorithm>
#include <sstream>
#include "Design_Pattern/Singleton.h"
#include "Design_Pattern/Factory.h"
#include "Design_Pattern/Product.h"
#include "C_Plus_Plus_Basic/BasicTest.h"
#include "gree.h"

using namespace horizon_analysis_server;

class A {
public:
    A() {
        t = 9;
        std::cout << "construct" << std::endl;
    }

    ~A() {
        t = 7;
        std::cout << "destruct" << std::endl;
    }

    A(const A &kkk) {
        std::cout << "copy" << std::endl;
    }

private:
    int t;
};

class Student {
public:
    bool getMoney() {
        return hasMoney_;
    }

    bool getPhone() {
        return hasPhone_;
    }

    friend std::ostream &
    operator<<(std::ostream &out, const Student &student1) {

    }

private:
    bool male;
    bool hasPhone_;
    bool hasMoney_;
    std::string name_;
    std::string address_;

};

void test() {
    std::shared_ptr<Person> sptr = std::make_shared<Person>(10, "xiaowang");
    std::cout << sptr->getAge() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

std::shared_ptr<Person> factory() {
//    Person *person = new Person(11, "xiaozhang");
    Person ppp(1, "jj");
    std::shared_ptr<Person> pppp = std::make_shared<Person>(
            ppp);//shared_ptr指向ppp对象
    return std::make_shared<Person>(10, "xiaoming");
}

std::shared_ptr<Person> use_factory() {
    auto ptr02 = factory();
    return ptr02;
}

//int (*fun)(int, int);

int test33() {
    Person *person = new Person(11, "xiaoli");
    std::cout << person->getAge() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    delete (person);
}

void tttt(int a, int b, int (*fun)(int, int)) {
    fun(a, b);
}

bool isNeed;

const int ipc_mt_mask = 0xFF; //mask
const int ipc_mt_video = 1; //视频
const int ipc_mt_video_data = 1 << 1; //结构化数据
const int ipc_mt_face_feature = 1 << 2; //人脸特征
const int ipc_mt_face = 1 << 3; //人脸抠图




inline std::int64_t getMilliSecond(void) {
    struct timespec ts = {0, 0};
    clock_gettime(CLOCK_REALTIME, &ts);
    return (std::int64_t)ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}


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


inline std::int64_t getSecond(void) {
    struct timespec ts = {0, 0};
    clock_gettime(CLOCK_REALTIME, &ts);
    return (std::int64_t)ts.tv_sec;
}

int main(int argc, char *argv[]) {

#if 0
    std::string str = "Hello";
    std::vector<std::string> v;
    //调用常规的拷贝构造函数，新建字符数组，拷贝数据
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";
    //调用移动构造函数，掏空str，掏空后，最好不要使用str。
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";
    std::cout << "The contents of the vector are \"" << v[0]
              << "\", \"" << v[1] << "\"\n";
#endif

#if 0
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int64_t curr_time_stamp = (tv.tv_sec * 1000 + tv.tv_usec / 1000);
#endif

#if 0
    auto kkk = use_factory();
    std::this_thread::sleep_for(std::chrono::seconds(6));
//    std::cout<<kkk->getAge()<<std::endl;
#endif

#if 0
    std::vector<std::string> v1;
    {
        std::vector<std::string> v2 = {"a", "an"};
        v1 = v2;
        std::cout<<v2[0]<<std::endl;
    }
    std::cout<<"haha"<<std::endl;
    std::cout<<v1[0]<<std::endl;
#endif

#if 0
    std::vector<int> vector1(3, 10);
    std::vector<int> vector2(4, 9);
    std::copy(vector1.begin(), vector1.end(), vector2.begin());
    for(auto & item : vector2) {
        std::cout << item << std::endl;
    }
    std::cout << "-----------------" <<std::endl;
    std::vector<int> v3 = {1};
    std::copy(vector1.begin(), vector1.end(), std::back_inserter(v3));
    for (auto & item1 : v3) {
        std::cout <<item1 <<std::endl;
    }
#endif


    auto gree_instance = Gree::GetInstance();
    gree_instance->init();
    gree_instance->start();
    gree_instance->wait();
    return EXIT_SUCCESS;
}





