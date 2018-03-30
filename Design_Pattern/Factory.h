//
// Created by yalin.han on 2017/11/13.
//

#ifndef PRO1_FACTORY_H
#define PRO1_FACTORY_H


#include "Product.h"

class Factory {
public:
    virtual ~Factory() = 0;

    virtual Product *createProduct() = 0;

protected:
    Factory();

private:
};


class ConcreteFactory : public Factory {
public:
    ConcreteFactory();

    ~ConcreteFactory();

    Product *createProduct();

protected:

private:
};


#endif //PRO1_FACTORY_H
