//
// Created by yalin.han on 2017/9/21.
//

#include <vector>
#include "Account.h"

const int Account::value_;
double Account::interestRate = 19;


void Account::rate(double newRate) {
    interestRate = newRate;
    std::vector<std::string> jpg_vector;

    for(auto item:jpg_vector){
        std::cout<<item<<std::endl;
    }
    for (auto iter = jpg_vector.cbegin(); iter!=jpg_vector.cend() ; ++iter) {
        std::cout<<*iter<<std::endl;
    }
}