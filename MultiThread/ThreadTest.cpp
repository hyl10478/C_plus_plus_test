//
// Created by yalin.han on 2017/8/19.
//

#include <mutex>
#include "ThreadTest.h"
#include <chrono>
#include <iostream>
#include <thread>

int value;
std::mutex mtx;

void print_block(int n, char c) {
    mtx.lock();
    for (int i = 0; i < n; ++i) {
        std::cout << c;
    }
    std::cout << "\n";
    mtx.unlock();
}

void print_block2(int n, char c) {
    std::unique_lock<std::mutex> lck(mtx);
    for (int i = 0; i < n; ++i) {
        std::cout << c ;
    }
    std::cout<<'\n';
}

void print_thread_id(int id) {
    mtx.lock();
    std::lock_guard<std::mutex> lck(mtx, std::adopt_lock);
    std::cout << "thread #" << id << '\n';
}

void print_even(int x) {
    if (x % 2 == 0) std::cout << x << " is even\n";
    else throw (std::logic_error("not even"));
}

void print_thread_id2(int id) {
    try {
        // using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
        std::lock_guard<std::mutex> lck(mtx);
        print_even(id);
    }
    catch (std::logic_error &) {
        std::cout << "[exception caught]\n";
    }
}

void increase_value() {
    std::lock_guard<std::mutex> lck(mtx);
    ++value;
    std::cout << std::this_thread::get_id() << ":" << value << std::endl;
}


void ThreadTest::test() {
    std::thread thread1(print_block, 50, '*');
    std::thread thread2(print_block, 50, '$');
    thread1.join();
    thread2.join();
    std::cout << "end" << std::endl;
}

void ThreadTest::test2() {
    std::thread threads[10];
    for (int i = 0; i < 10; ++i) {
        threads[i] = std::thread(print_thread_id2, i + 1);
    }
    for (auto &th : threads) {
        th.join();
    }
}

void ThreadTest::test3() {
    std::cout << __func__ << ":" << value << std::endl;
    std::thread th1(increase_value);
    std::thread th2(increase_value);
    std::thread th3(increase_value);
    th3.join();
    th1.join();
    th2.join();
    std::cout << __func__ << ":" << value << std::endl;
}

void ThreadTest::test4() {

    std::thread th1(print_block2, 50, '#');
    std::thread th2(print_block2, 50, '$');
    th1.join();
    th2.join();
}
