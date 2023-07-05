/*
 * Factory.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
定义一个用于创建对象的接口，让子类决定实例化哪一个类。Factory Method使一个类的实例化延迟到其子类。
*/

/*
抽象基类:
1)Product:创建出来的对象的抽象基类.
2)Factory 创建对象的工厂方法的抽象基类.

接口函数:
 1)Creator::FactoryMethod:纯虚函数,由派生类实现,创建出对应的 Product.

解析:
在这个模式中,有两个抽象基类,一个是 Product 为创建出来的对象的抽象基类,
一个是 Factory 是工厂的抽象基类,在互相协作的时候都是由相应的 Factory 派生类来生成 Product 的派生类,
也就是说如果要新增一种 Product 那么也要对应的新增一个 Factory,创建的过程委托给了这个 Factory.
也就是说一个 Factory 和一个 Product 是一一对应的关系.
*/

NAMESPACE_START

class Product {
public: 
    Product(){}
    virtual ~Product(){} 
};

class ConcreateProduct : public Product
{ 
public:
    ConcreateProduct()
    {
        std::cout << "destruction of ConcreateProduct\n";
    }

    virtual ~ConcreateProduct()
    {
        std::cout << "destruction of ConcreateProduct\n";
    }
};

class Creator 
{
public: 
    Creator(){}
    virtual ~Creator(){} 
    void AnOperation()
    {
        Product *p = FactoryMethod();
        std::cout << "an operation of product\n";
        delete p;
    }

protected:
    virtual Product* FactoryMethod() = 0;
};

class ConcreateCreator : public Creator
{
public:
    ConcreateCreator()
    {
        std::cout << "construction of ConcreateCreator\n";
    }

    virtual ~ConcreateCreator()
    {
        std::cout << "construction of ConcreateCreator\n";
    }

protected:
    virtual Product* FactoryMethod()
    {
        return new ConcreateProduct();
    }
};

void testFactory(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testFactory start--------------------------------"<<std::endl;
    
    Creator *p = new ConcreateCreator(); 
    p->AnOperation();
    delete p;
    
    std::cout<<"---------------------------testFactory end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !FACTORY_HPP */
