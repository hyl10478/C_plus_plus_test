//
// Created by yalin.han on 2017/11/13.
//

#ifndef PRO1_SINGLETON_H
#define PRO1_SINGLETON_H


class Singleton {
public:
    static Singleton *getInstance();
    ~Singleton();

private:
    Singleton();
    static Singleton *instance_;
};


#endif //PRO1_SINGLETON_H
