/*
 * Adapt.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef ADAPT_HPP
#define ADAPT_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
将一个类的接口转换成客户希望的另外一个接口。
Adapt 模式使得原本由于接口不兼容而不能一起工作的那些类可以一起工作。
*/

/*
1)采用继承原有接口类的方式
2)采用组合原有接口类的方式

解析:
Adapt模式其实就是把完成同样的一个功能但是接口不能兼容的类桥接在一起使之可以在一起工作,这个模式使得复用旧的接口成为可能.

实现:
Adapt模式有两种实现办法,一种是采用继承原有接口类的方法,一种是采用组 合原有接口类的方法,这里采用的是第二种实现方法.
*/

NAMESPACE_START

// 需要被 Adapt 的类 
class Target
{ 
public:
    Target(){}
    virtual ~Target() {}
    virtual void Request() = 0; 
};

// 与被 Adapt 对象提供不兼容接口的类 
class Adaptee
{ 
public:
    Adaptee(){}
    ~Adaptee(){}
    void SpecialRequest()
    {
        std::cout << "SpecialRequest of Adaptee\n";
    }
};

// 进行 Adapt 的类,采用聚合原有接口类的方式 
class Adapter : public Target 
{
public:
    Adapter(Adaptee* pAdaptee) : m_pAdptee(pAdaptee) {}

    virtual ~Adapter()
    {
        delete m_pAdptee;
        m_pAdptee = NULL;
    }

    virtual void Request()
    {
        std::cout << "Request of Adapter\n";
        m_pAdptee->SpecialRequest();
    }

private:
    Adaptee* m_pAdptee;
};


void testAdapt(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testAdapt start--------------------------------"<<std::endl;
    
    Adaptee *pAdaptee = new Adaptee;
    Target *pTarget = new Adapter(pAdaptee); 
    pTarget->Request();
    
    delete pTarget;
    
    std::cout<<"---------------------------testAdapt end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !ADAPT_HPP */
