/*
 * Prototype.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef PROTOTYPE_HPP
#define PROTOTYPE_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。
*/

/*
抽象基类:
1)Prototype:虚拟基类,所有原型的基类,提供 Clone 接口函数

接口函数:
1)Prototype::Clone 函数:纯虚函数,根据不同的派生类来实例化创建对象.

解析:
Prototype模式其实就是常说的"虚拟构造函数"一个实现,C++的实现机制中并没有支持这个特性,
但是通过不同派生类实现的 Clone 接口函数可以完成与"虚 拟构造函数"同样的效果.
举一个例子来解释这个模式的作用,假设有一家店铺是配钥匙的,他对外提供配制钥匙的服务(提供Clone接口函数),
你需要配什么钥匙它不知道只是提供这种服务,具体需要配什么钥匙只有到了真正看到钥匙的原型才能配好.
也就是说,需要一个提供这个服务的对象,同时还需要一个原型(Prot otype),不然不知道该配什么样的钥匙.
*/

NAMESPACE_START

class Prototype 
{
public:
    Prototype(){}
    virtual ~Prototype(){} 
    virtual Prototype* Clone() = 0;
};

// 派生自 Prototype,实现 Clone 方法 
class ConcreatePrototype1 : public Prototype 
{
public:
    ConcreatePrototype1()
    {
        std::cout << "construction of ConcreatePrototype1\n";
    }

    ConcreatePrototype1(const ConcreatePrototype1&)
    {
        std::cout << "copy construction of ConcreatePrototype1\n";
    }

    virtual ~ConcreatePrototype1()
    {
        std::cout << "destruction of ConcreatePrototype1\n";
    }

    virtual Prototype* Clone()
    {
        std::cout << "Clone of ConcreatePrototype1\n";
        return new ConcreatePrototype1(*this);
    }
};

// 派生自 Prototype,实现 Clone 方法 
class ConcreatePrototype2 : public Prototype 
{
public:
    ConcreatePrototype2()
    {
        std::cout << "construction of ConcreatePrototype2\n";
    }

    ConcreatePrototype2(const ConcreatePrototype2&)
    {
        std::cout << "copy construction of ConcreatePrototype2\n";
    }

    virtual ~ConcreatePrototype2()
    {
        std::cout << "destruction of ConcreatePrototype2\n";
    }

    virtual Prototype* Clone()
    {
        std::cout << "Clone of ConcreatePrototype2\n";
        return new ConcreatePrototype2(*this);
    }
};


void testPrototype(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testPrototype start--------------------------------"<<std::endl;
    
    Prototype *pPrototype1 = new ConcreatePrototype1(); 
    Prototype *pPrototype2 = pPrototype1->Clone();

    Prototype *pPrototype3 = new ConcreatePrototype2(); 
    Prototype *pPrototype4 = pPrototype3->Clone();

    delete pPrototype1;
    delete pPrototype2; 
    delete pPrototype3; 
    delete pPrototype4;
    
    std::cout<<"---------------------------testPrototype end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !PROTOTYPE_HPP */
