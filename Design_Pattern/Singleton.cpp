//
// Created by yalin.han on 2017/11/13.
//

#include <iostream>
#include "Singleton.h"

Singleton* Singleton::instance_ = nullptr;
Singleton* Singleton::getInstance() {
    if(instance_ == nullptr){
        instance_ = new Singleton();
    }
    return instance_;
}

Singleton::Singleton(){
    std::cout<<"create"<<std::endl;
}

Singleton::~Singleton() {
    std::cout<<"destructor"<<std::endl;
}
