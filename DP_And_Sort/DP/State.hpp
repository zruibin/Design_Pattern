/*
 * State.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
允许一个对象在其内部状态改变时改变它的行为.
*/

/*
解析:
State模式主要解决的是在开发中时常遇到的根据不同的状态需要进行不同的处理操作的问题,而这样的问题,大部分人是采用 switch-case语句进行处理的, 这样会造成一个问题:分支过多,而且如果加入一个新的状态就需要对原来的代码进行编译.
State 模式采用了对这些不同的状态进行封装的方式处理这类问题, 当状态改变的时候进行处理然后再切换到另一种状态,也就是说把状态的切换责任交给了具体的状态类去负责.
同时,State 模式和 Strategy 模式在图示上有很多相似的地方,需要说明的是两者的思想都是一致的,只不过封装的东西不同:State模式封装的是不同的状态,而 Stategy 模式封装的是不同的算法.
*/

NAMESPACE_START

class SState;

class SContext 
{
public:
    SContext(SState* pState) : m_pState(pState) {} 
    ~SContext();
    void Request();
    void ChangeState(SState *pState);

private:
    SState *m_pState;
};

class SState
{
public:
    virtual ~SState(){}
    virtual void Handle(SContext* pContext) = 0; 
};

class ConcreateStateB;

class ConcreateStateA : public SState
{ 
public:
    void Handle(SContext* pContext);
};

class ConcreateStateB : public SState
{ 
public:
    void Handle(SContext* pContext);
};


SContext::~SContext()
{
    delete m_pState;
    m_pState = NULL;
}

void SContext::Request()
{
    if (NULL != m_pState) {
        m_pState->Handle(this); 
    }
}

void SContext::ChangeState(SState *pState)
{
    if (NULL != m_pState) {
        delete m_pState;
        m_pState = NULL; 
    }
    m_pState = pState;
}

void ConcreateStateA::Handle(SContext* pContext)
{
    std::cout << "Handle by ConcreateStateA\n";
    if (NULL != pContext) {
        pContext->ChangeState(new ConcreateStateB()); 
    }
}

void ConcreateStateB::Handle(SContext* pContext)
{
    std::cout << "Handle by ConcreateStateB\n";
    if (NULL != pContext) {
        pContext->ChangeState(new ConcreateStateA()); 
    }
}

void testState(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testState start--------------------------------"<<std::endl;
    
    SState *pState = new ConcreateStateA(); 
    SContext *pContext = new SContext(pState); 
    pContext->Request();
    pContext->Request(); 
    pContext->Request();
    
    delete pContext;
    
    std::cout<<"---------------------------testState end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !STATE_HPP */
