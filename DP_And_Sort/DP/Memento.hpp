/*
 * Memento.hpp
 *
 * Created by Ruibin.Chow on 2020/08/18.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef MEMENTO_HPP
#define MEMENTO_HPP

#include <iostream>
#include <string>
#include "Macros.h"

/*
作用: 
在不破坏封装性的前提下,捕获一个对象的内部状态,并在该对象之外保存这个状态.
这样以后就可将该对象恢复到原先保存的状态.
*/

/*
解析:
Memento模式中封装的是需要保存的状态,当需要恢复的时候才取出来进行恢复.
原理很简单,实现的时候需要注意一个地方:窄接口和宽接口.
所谓的宽接口就是一般意义上的接口,把对外的接口作为public成员;
而窄接口反之,把接口作为private成员,而把需要访问这些接口函数的类作为这个类的友元类,
也就是说接口只暴露给了对这些接口感兴趣的类,而不是暴露在外部.
下面的实现就是窄实现的方法来实现的.
*/

NAMESPACE_START

using MState = std::string;

class Originator;

// 把Memento的接口函数都设置为私有的,而Originator是它的友元, 
// 这样保证了只有 Originator 可以对其访问
class Memento
{ 
private:
    friend class Originator;

    Memento(const MState& rState) : m_State(rState) {}

    void SetState(const MState& rState)
    {
        m_State = rState;
    }

    MState GetState()
    {
        return m_State;
    }

private:
    MState m_State; 
};

class Originator 
{
public:
    Originator(const MState& rState) : m_State(rState) {} 
    Originator() {}
    ~Originator() {}
    
    Memento* CreateMemento()
    {
        return new Memento(m_State);
    }

    void RestoreState(Memento* pMemento)
    {
        if (NULL != pMemento) {
            m_State = pMemento->GetState();
        }
    }

    MState GetState()
    {
        return m_State;
    }

    void SetState(const MState& rState)
    {
        m_State = rState;
    }

    void PrintState()
    {
        std::cout << "State = " << m_State << std::endl;
    }

private:
    MState m_State;
};



void testMemento(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testMemento start--------------------------------"<<std::endl;
    
    // 创建一个原发器
    Originator* pOriginator = new Originator("old state"); 

    pOriginator->PrintState();
    // 创建一个备忘录存放这个原发器的状态
    Memento *pMemento = pOriginator->CreateMemento();
    // 更改原发器的状态 
    pOriginator->SetState("new state"); 
    pOriginator->PrintState();
    // 通过备忘录把原发器的状态还原到之前的状态 
    pOriginator->RestoreState(pMemento); 
    pOriginator->PrintState();
    
    delete pOriginator; 
    delete pMemento;

    std::cout<<"---------------------------testMemento end--------------------------------"<<std::endl;
}

NAMESPACE_END


#endif /* !MEMENTO_HPP */
