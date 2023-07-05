/*
 * AbstractFactory.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef ABSTRACTFACTORY_HPP
#define ABSTRACTFACTORY_HPP

#include <iostream>
#include "Macros.h"

/**
作用: 
提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。
*/

/*
抽象基类: 
1)ProductA,ProductB:分别代表不同类型的产品,而它们的派生类则是这种产 品的一个实现. 
2)AbstractFactory:生产这一系列产品的一个抽象工厂,它的派生类是不同的 实现.

接口函数:
1)AbstractFactory::CreateProductA 和 AbstractFactory::CreateProductB:分别是生产不同产品的不同的实现,由各个派生出来的抽象工厂实现之.

解析:
Abstract Factory模式和Factory最大的差别就是抽象工厂创建的是一系列相 关的对象,其中创建的实现其实采用的就是 Factory 模式的方法,对于某个实现 的有一个派生出来的抽象工厂,另一个实现有另一个派生出来的工厂,等等.
可以举一个简单的例子来解释这个模式:比如,同样是鸡腿(ProductA)和汉堡(ProductB),
它们都可以有商店出售(AbstractFactory),但是有不同的实现,有肯 德基(ConcreateFactory1)和麦当劳(ConcreateFactory2)两家生产出来的不同风味的鸡腿和汉堡(也就是 ProductA 和 ProductB 的不同实现). 
而负责生产汉堡和鸡腿的就是之前提过的 Factory 模式了.
抽象工厂需要特别注意的地方就是区分不同类型的产品和这些产品的不同实现. 
显而易见的,如果有 n 种产品同时有 m 中不同的实现,那么根据乘法原理可知有 n *m 个 Factory 模式的使用.
*/

NAMESPACE_START

// 抽象基类 AbstractProductA,代表产品 A 的抽象 
class AbstractProductA
{ 
public:
    AbstractProductA() {}
    virtual ~AbstractProductA(){}
};

// 派生类 ConcreateProductA1,继承自 AbstractProductA,代表产品 A 的第一种实现 
class ConcreateProductA1 : public AbstractProductA 
{
public:
    ConcreateProductA1()
    {
        std::cout << "construction of ConcreateProductA1\n";
    }

    virtual ~ConcreateProductA1()
    {
        std::cout << "destruction of ConcreateProductA1\n";
    }
};

// 派生类 ConcreateProductA2,继承自 AbstractProductA,代表产品 A 的第二种实现
class ConcreateProductA2 : public AbstractProductA 
{
public:
    ConcreateProductA2()
    {
        std::cout << "construction of ConcreateProductA2\n";
    }

    virtual ~ConcreateProductA2()
    {
        std::cout << "destruction of ConcreateProductA2\n";
    }
};

// 抽象基类 AbstractProductB,代表产品 B 的抽象 
class AbstractProductB
{
public:
    AbstractProductB() {}
    virtual ~AbstractProductB(){}; 
};

// 派生类 ConcreateProductB1,继承自 AbstractProductB,代表产品 B 的第一种实现 
class ConcreateProductB1 : public AbstractProductB 
{
public:
    ConcreateProductB1()
    {
        std::cout << "construction of ConcreateProductB1\n";
    }

    virtual ~ConcreateProductB1()
    {
        std::cout << "destruction of ConcreateProductB1\n";
    }
};

// 派生类 ConcreateProductB2,继承自 AbstractProductB,代表产品 B 的第二种实现 
class ConcreateProductB2 : public AbstractProductB {
public:
    ConcreateProductB2()
    {
        std::cout << "construction of ConcreateProductB2\n";
    }

    virtual ~ConcreateProductB2()
    {
        std::cout << "destruction of ConcreateProductB2\n";
    }
};

// 抽象基类 AbstractFactory,工厂的抽象类,生产产品 A 和产品 B 
class AbstractFactory
{ 
public:
    AbstractFactory(){}
    virtual ~AbstractFactory(){}
    virtual AbstractProductA* CreateProductA() = 0; 
    virtual AbstractProductB* CreateProductB() = 0;
};

// 派生类 ConcreateFactory1,继承自 AbstractFactory // 生产产品 A 和产品 B 的第一种实现
class ConcreateFactory1 : public AbstractFactory 
{
public:
    ConcreateFactory1()
    {
        std::cout << "construction of ConcreateFactory1\n";
    }

    virtual ~ConcreateFactory1()
    {
        std::cout << "destruction of ConcreateFactory1\n";
    }

    virtual AbstractProductA* CreateProductA()
    {
        return new ConcreateProductA1(); 
    }

    virtual AbstractProductB* CreateProductB()
    {
        return new ConcreateProductB1();
    }
};

// 派生类 ConcreateFactory2,继承自 AbstractFactory // 生产产品 A 和产品 B 的第二种实现
class ConcreateFactory2 : public AbstractFactory 
{
public:
    ConcreateFactory2()
    {
        std::cout << "construction of ConcreateFactory2\n";
    }

    virtual ~ConcreateFactory2()
    {
        std::cout << "destruction of ConcreateFactory2\n";
    }

    virtual AbstractProductA* CreateProductA()
    {
        return new ConcreateProductA2(); 
    }

    virtual AbstractProductB* CreateProductB()
    {
        return new ConcreateProductB2();
    }
};

void testAbstractFactory(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testAbstractFactory start--------------------------------"<<std::endl;
    
    // 生产产品 A 的第一种实现
    ConcreateFactory1 *pFactory1 = new ConcreateFactory1; AbstractProductA *pProductA = pFactory1->CreateProductA();
    // 生产产品 B 的第二种实现
    ConcreateFactory2 *pFactory2 = new ConcreateFactory2; AbstractProductB *pProductB = pFactory2->CreateProductB();

    delete pFactory1; 
    delete pProductA; 
    delete pFactory2; 
    delete pProductB;
    
    std::cout<<"---------------------------testAbstractFactory end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !ABSTRACTFACTORY_HPP */
