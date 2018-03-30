//
// Created by yalin.han on 2017/9/21.
//

#ifndef PRO1_ACCOUNT_H
#define PRO1_ACCOUNT_H

#include <iostream>

class Account {
public:
    void calculate() { amount += amount * interestRate; }

    static double rate() { return interestRate; }

    static void rate(double);


private:
    std::string owner;
    double amount;
    static double interestRate;

    static const int value_ = 22;

    static double initRate();
};

#endif //PRO1_ACCOUNT_H
