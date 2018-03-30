//
// Created by yalin.han on 2017/11/13.
//

#include <iostream>
#include "Product.h"

Product::Product() {

}

Product::~Product(){

}

void Product::printInfo() {
    std::cout<<"base print infomation..."<<std::endl;
}

ConcreteProduct::ConcreteProduct() {
    std::cout<<"ConcreteProduct....."<<std::endl;
}

ConcreteProduct::~ConcreteProduct(){
    std::cout<<"concrete product destructor..."<<std::endl;
}

void ConcreteProduct::printInfo() {
    std::cout<<"print infomation..."<<std::endl;
}

