//
// Created by yalin.han on 2017/11/13.
//

#include <iostream>
#include "Factory.h"
#include "Product.h"

Factory::Factory() {

}

Factory::~Factory() {

}


ConcreteFactory::ConcreteFactory() {

}

ConcreteFactory::~ConcreteFactory() {
    std::cout<<"concrete factory destructor....."<<std::endl;
}

Product* ConcreteFactory::createProduct() {
    std::cout<<"create product...."<<std::endl;
    return new ConcreteProduct();
}