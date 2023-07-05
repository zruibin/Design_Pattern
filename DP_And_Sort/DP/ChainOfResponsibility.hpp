/*
 * ChainOfResponsibility.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef CHAINOFRESPONSIBILITY_HPP
#define CHAINOFRESPONSIBILITY_HPP

#include <iostream>
#include "Macros.h"

/*
作用: 
使多个对象都有机会处理请求,从而避免请求的发送者和接收者之间的耦合关系. 
将这些对象连成一条链，并沿着这条链传递该请求,直到有一个对象处理它为止.
*/

/*
抽象基类:
1)Handler:定义一个处理请求的接口,在图中这个接口就是 HandleRequset 函数,
这个类同时有一个指向 Handler 对象的指针,指向后续的处理请求的对象(如果有的话).

解析: 
这个模式把可以处理一个请求的对象以链的形式连在了一起,让这些对象都有处理请求的机会.
好比原来看古装电视中经常看到皇宫中召见某人的时候,太监们 (可以处理一个请求的对象)就会依次的喊:传 XX...这样一直下去直到找到这个人为止.
ChainOfResponsibility模式也是这样的处理请求的,如果有后续的对象可以处理,那么传给后续的对象处理,否则就自己处理请求.
这样的设计把请求的发送者和请求这种的处理者解耦了,好比发号的皇帝不知道到底是哪个太监最 后会找到他要找到的人一般,只管发出命令就OK了.
*/

NAMESPACE_START

// 抽象基类,定义一个处理请求的接口 
class Handler
{
public:
    Handler(Handler *pSuccessor = nullptr) : m_pSuccessor(pSuccessor) {} 
    virtual ~Handler()
    {
        delete m_pSuccessor;
        m_pSuccessor = NULL;
    }

    // 纯虚函数,由派生类实现
    virtual void HandleRequset() = 0;
protected:
    Handler* m_pSuccessor;
};

class ConcreateHandler1 : public Handler
{ 
public:
    ConcreateHandler1(Handler *pSuccessor = nullptr) : Handler(pSuccessor) {} 
    virtual ~ConcreateHandler1() {}

    virtual void HandleRequset()
    {
        if (NULL != m_pSuccessor) {
            m_pSuccessor->HandleRequset(); }
        else {
            std::cout << "HandleRequset by ConcreateHandler1\n";
        }
    }
};

class ConcreateHandler2 : public Handler
{
public:
    ConcreateHandler2(Handler *pSuccessor = nullptr) : Handler(pSuccessor) {} 
    virtual ~ConcreateHandler2() {}

    virtual void HandleRequset()
    {
        if (NULL != m_pSuccessor) {
            m_pSuccessor->HandleRequset(); }
        else {
            std::cout << "HandleRequset by ConcreateHandler2\n";
        }
    }
};

void testChainOfResponsibility(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testChainOfResponsibility start--------------------------------"<<std::endl;
    
    Handler *p1 = new ConcreateHandler1(); 
    Handler *p2 = new ConcreateHandler2(p1);
    p2->HandleRequset(); 
    
    delete p2;
    
    std::cout<<"---------------------------testChainOfResponsibility end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !CHAINOFRESPONSIBILITY_HPP */
