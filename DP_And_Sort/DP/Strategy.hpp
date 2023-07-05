/*
 * Strategy.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
定义一系列的算法,把它们一个个封装起来, 并且使它们可相互替换.
本模式使得算法可独立于使用它的客户而变化.
*/

/*
解析:
简而言之一句话,Strategy模式是对算法的封装.
处理一个问题的时候可能有多种算法,这些算法的接口(输入参数,输出参数等)都是一致的,那么可以考虑采用 Strategy 模式对这些算法进行封装,在基类中定义一个函数接口就可以了.
*/

NAMESPACE_START

class Strategy 
{
public:
    virtual ~Strategy(){}
    virtual void AlgorithmInterface() = 0; 
};

class ConcreateStrategyA : public Strategy
{ 
public:
    virtual ~ConcreateStrategyA() {} 
    virtual void AlgorithmInterface()
    {
        std::cout << "AlgorithmInterface Implemented by ConcreateStrategyA\n";
    }
};

class Context 
{
public:
    Context(Strategy *pStrategy) : m_pStrategy(pStrategy) {}
    
    ~Context()
    {
        delete m_pStrategy;
        m_pStrategy = NULL;
    }

    void ContextInterface()
    {
        if (NULL != m_pStrategy) {
            m_pStrategy->AlgorithmInterface(); 
        }
    }

private:
    Strategy *m_pStrategy; 
};


void testStrategy(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testStrategy start--------------------------------"<<std::endl;
    
    Strategy *pStrategy = new ConcreateStrategyA(); 
    Context *pContext = new Context(pStrategy);
    pContext->ContextInterface();
    
    delete pContext;
    
    std::cout<<"---------------------------testStrategy end--------------------------------"<<std::endl;
}

NAMESPACE_END


#endif /* !STRATEGY_HPP */
