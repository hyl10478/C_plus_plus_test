//
// Created by yalin.han on 2018/3/30.
//

#include "gree.h"


namespace horizon_analysis_server {
    Gree* Gree::GetInstance() {
        static Gree *gree = nullptr;
        if (gree == nullptr){
            gree = new Gree(3, "xiaoming");
        }
        return gree;
    }

    Gree::Gree(int age, std::string name) : age_(age), name_(name){
        std::cout << "construct..." << std::endl;
    }

    void Gree::init() {
        std::cout << "init..." << std::endl;
    }

    bool Gree::pro() {
        std::cout << "pro..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return true;
    }

}