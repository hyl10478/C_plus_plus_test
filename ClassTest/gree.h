//
// Created by yalin.han on 2018/3/30.
//

#ifndef PRO1_GREE_H
#define PRO1_GREE_H

#include <loop.h>
#include <iostream>

namespace horizon_analysis_server {
    class Gree : public loop {
    public:
        static Gree *GetInstance();
        void init();

    private:
        Gree(int age, std::string name_);
        bool pro() override ;
        int age_;
        std::string name_;
    };
}


#endif //PRO1_GREE_H
