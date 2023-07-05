/*
 * Flyweight.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef FLYWEIGHT_HPP
#define FLYWEIGHT_HPP

#include <iostream>
#include <string> 
#include <list>
#include "Macros.h"

/*
作用: 运用共享技术有效地支持大量细粒度的对象。
*/

/*
解析:
Flyweight 模式在大量使用一些可以被共享的对象的时候经常使用.
比如,在 QQ 聊天的时候很多时候你懒得回复又不得不回复的时候,一般会用一些客套的话语 敷衍别人,如"呵呵","好的"等等之类的,这些简单的答复其实每个人都是提前定义好的,在使用的时候才调用出来.
Flyweight 就是基于解决这种问题的思路而产生的,当需要一个可以在其它地方共享使用的对象的时候,先去查询是否已经存在了同样的对象,如果没有就生成之有的话就直接使用.
因此,Flyweight 模式 和 Factory 模式也经常混用.

实现: 
需要说明的是下面的实现仅仅实现了对可共享对象的使用,非可共享对象的使用没有列出,因为这个不是 Flyweight 模式的重点.
这里的实现要点是采用一个 list 链表来保存这些可以被共享的对象,需要使用的时候就到链表中查询是不是已经存在了,如果不存在就初始化一个,然后返回这个对象的指针.
*/

NAMESPACE_START

using State = std::string;

class Flyweight 
{
public:
    virtual ~Flyweight() {}

    State GetIntrinsicState()
    {
        return m_State;
    }

    virtual void Operation(State& ExtrinsicState) = 0;

protected:
    Flyweight(const State& state) : m_State(state) {}

private:
    State m_State;
};

class ConcreateFlyweight : public Flyweight
{ 
public:
    ConcreateFlyweight(const State& state) : Flyweight(state) {}
    virtual ~ConcreateFlyweight() {}
    virtual void Operation(State& ExtrinsicState) {}
};

class FlyweightFactory 
{
public: 
    FlyweightFactory() {}

    ~FlyweightFactory()
    {
        std::list<Flyweight*>::iterator iter1, iter2, temp;
        for (iter1 = m_listFlyweight.begin(), iter2 = m_listFlyweight.end(); iter1 != iter2;) {
            temp = iter1; 
            ++iter1;
            delete (*temp);
        }
        m_listFlyweight.clear();
    }

    Flyweight* GetFlyweight(const State& key)
    {
        std::list<Flyweight*>::iterator iter1, iter2;
        for (iter1 = m_listFlyweight.begin(), iter2 = m_listFlyweight.end(); 
            iter1 != iter2; ++iter1) {
            if ((*iter1)->GetIntrinsicState() == key) {
                std::cout << "The Flyweight:" << key << " already exits"<< std::endl; 
                return (*iter1);
            }
        }
        std::cout << "Creating a new Flyweight:" << key << std::endl; 
        Flyweight* flyweight = new ConcreateFlyweight(key); 
        m_listFlyweight.push_back(flyweight);
        return flyweight;
    }

private:
    std::list<Flyweight*> m_listFlyweight;
};


void testFlyweight(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testFlyWeight start--------------------------------"<<std::endl;
    
    FlyweightFactory flyweightfactory; 
    flyweightfactory.GetFlyweight("hello"); 
    flyweightfactory.GetFlyweight("world"); 
    flyweightfactory.GetFlyweight("hello");
    
    std::cout<<"---------------------------testFlyWeight end--------------------------------"<<std::endl;
}

NAMESPACE_END


#endif /* !FLYWEIGHT_HPP */
