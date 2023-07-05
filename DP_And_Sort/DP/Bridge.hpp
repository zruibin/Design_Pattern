/*
 * Bridge.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef BRIDGE_HPP
#define BRIDGE_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
将抽象部分与它的实现部分分离，使它们都可以独立地变化。
*/

/*
抽象基类:
1)Abstraction:某个抽象类,它的实现方式由 Implementor 完成. 
2)Implementor:实现类的抽象基类,定义了实现 Abastraction 的基本操作,而 它的派生类实现这些接口.

接口函数:
1)Implementor::OperationImpl:定义了为实现 Abstraction 需要的基本操作,由 Implementor 的派生类实现之,而在 Abstraction::Operation 函数中根 据不同的指针多态调用这个函数.

解析:
Bridge 用于将表示和实现解耦,两者可以独立的变化.在 Abstraction 类中维护一个 Implementor 类指针,需要采用不同的实现方式的时候只需要传入不同的 Implementor 派生类就可以了.

Bridge 的实现方式其实和 Builde 十分的相近,可以这么说:本质上是一样的,只是封装的东西不一样罢了.
两者的实现都有如下的共同点:
抽象出来一个基类,这个基类里面定义了共有的一些行为,形成接口函数(对接口编程而不是对实现编 程),这个接口函数在 Buildier 中是 BuildePart 函数在 Bridge 中是 Operation Impl 函数;
其次,聚合一个基类的指针,如 Builder 模式中 Director 类聚合了一 个 Builder 基类的指针,而 Brige 模式中 Abstraction 类聚合了一个 Impleme ntor 基类的指针(优先采用聚合而不是继承);
而在使用的时候,都把对这个类的使用封装在一个函数中,在 Bridge 中是封装在 Director::Construct 函数中,因为装配不同部分的过程是一致的,而在 Bridge 模式中则是封装在 Abstraction:: Operation 函数中,在这个函数中调用对应的 Implementor::OperationImpl 函数.
就两个模式而言,Builder 封装了不同的生成组成部分的方式,而 Bridge 封 装了不同的实现方式.
因此,如果以一些最基本的面向对象的设计原则来分析这些模式的实现的话,还 是可以看到很多共同的地方的.
*/

NAMESPACE_START

// 为实现 Abstraction 定义的抽象基类,定义了实现的接口函数 
class Implementor
{
public:
    Implementor() {}
    virtual ~Implementor() {}
    virtual void OperationImpl() = 0; 
};

// 继承自 Implementor,是 Implementor 的不同实现之一 
class ConcreateImplementorA : public Implementor 
{
public:
    ConcreateImplementorA() {}
    virtual ~ConcreateImplementorA() {}
    virtual void OperationImpl()
    {
        std::cout << "Implementation by ConcreateImplementorA\n";
    }
};

// 继承自 Implementor,是 Implementor 的不同实现之一 
class ConcreateImplementorB : public Implementor 
{
public:
    ConcreateImplementorB() {}
    virtual ~ConcreateImplementorB(){ }
    virtual void OperationImpl()
    {
        std::cout << "Implementation by ConcreateImplementorB\n";
    } 
};


// 维护一个 Implementor 类的指针 
class Abstraction
{
public:
    Abstraction(Implementor* pImplementor) : m_pImplementor(pImplementor) {}

    virtual ~Abstraction()
    {
        delete m_pImplementor;
        m_pImplementor = NULL;
    }

    void Operation()
    {
        m_pImplementor->OperationImpl();
    }

protected:
    Implementor* m_pImplementor;
};



void testBridge(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testBridge start--------------------------------"<<std::endl;
    
    ConcreateImplementorA *pImplA = new ConcreateImplementorA(); 
    Abstraction *pAbstraction1 = new Abstraction(pImplA); 
    pAbstraction1->Operation();

    ConcreateImplementorB *pImplB = new ConcreateImplementorB(); 
    Abstraction *pAbstraction2 = new Abstraction(pImplB); 
    pAbstraction2->Operation();

     delete pAbstraction1; 
     delete pAbstraction2;
    
    std::cout<<"---------------------------testBridge end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !BRIDGE_HPP */
