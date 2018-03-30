//
// Created by yalin.han on 2017/8/19.
//

#ifndef PRO1_PERSON_H
#define PRO1_PERSON_H


#include <cstdint>
#include <iostream>

class Person {
    friend int32_t getTheAge(Person &person);

public:

    Person() = default;

    Person(unsigned age, std::string name);

    ~Person();

    std::string getName() const { return name_; }

    int32_t getAge() const { return age_; }

    int32_t calculate() const;

    int32_t calculate();

private:
    int32_t age_ = 10;
    std::string name_ = "xiaoming";
};

int32_t getTheAge(Person &person);

#endif //PRO1_PERSON_H
