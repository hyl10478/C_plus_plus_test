//
// Created by yalin.han on 2017/11/13.
//

#ifndef PRO1_PRODUCT_H
#define PRO1_PRODUCT_H


class Product {
public:
    virtual ~Product() = 0;

    virtual void printInfo();

protected:
    Product();

private:
};

class ConcreteProduct : public Product {
public:
    ConcreteProduct();

    ~ConcreteProduct();

    void printInfo() override;

protected:

private:
};


#endif //PRO1_PRODUCT_H
