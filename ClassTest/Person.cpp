//
// Created by yalin.han on 2017/8/19.
//

#include "Person.h"

int32_t getTheAge(Person &person) {
    return person.age_;
}

int32_t Person::calculate() const {
    return age_ * 2;
}

int32_t Person::calculate() {
    return age_ * 4;

}

Person::Person(unsigned age, std::string name) : age_(age), name_(name) {

}

Person::~Person() {
    std::cout<<"destructor..."<<std::endl;
}