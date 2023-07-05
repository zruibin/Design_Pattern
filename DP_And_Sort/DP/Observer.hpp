/*
 * Observer.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef OBSERVER_HPP
#define OBSERVER_HPP


#include <iostream>
#include <list>
#include <algorithm>
#include "Macros.h"

/*
作用: 
定义对象间的一种一对多的依赖关系,当一个对象的状态发生改变时,所有依赖于它的对象都得到通知并被自动更新.
*/

/*
解析:
Observer 模式定义的是一种一对多的关系,这里的一就是图中的 Subject 类, 而多则是 Obesrver 类,
当 Subject 类的状态发生变化的时候通知与之对应的 Obesrver 类们也去相应的更新状态,
同时支持动态的添加和删除 Observer 对象的功能.Obesrver 模式的实现要点是,
第一一般 subject 类都是采用链表等容器来存放 Observer 对象,
第二抽取出 Observer 对象的一些公共的属性形成 Observer 基类,而 Subject 中保存的则是 Observer 类对象的指针,
这样就使 Subject 和具体的 Observer 实现了解耦,也就是 Subject 不需要去关心到底是哪个 Observer 对放进了自己的容器中.
生活中有很多例子可以看做是 Observer 模式的运用,比方说,一个班有一个班主任(Subject),他管理手下的一帮学生(Obs erver),当班里有一些事情发生需要通知学生的时候,班主任要做的不是逐个学生挨个的通知而是把学生召集起来一起通知,实现了班主任和具体学生的关系解耦.
*/


NAMESPACE_START

typedef int STATE;

class OSubject;

// Observer 抽象基类 
class Observer
{
public:
    Observer() : m_nObserverState(-1) {} 
    virtual ~Observer(){}
    
    // 纯虚函数,各个派生类可能有不同的实现
    // 通知 Observer 状态发生了变化
    virtual void Update(OSubject* pSubject) = 0;
protected:
    STATE m_nObserverState; // 模拟保存 Observer 状态的变量
};

// Subject 抽象基类,只需要知道 Observer 基类的声明就可以了 
class OSubject
{
public:
    OSubject() : m_nSubjectState(-1) {} 
    virtual ~OSubject()
    {
        std::list<Observer*>::iterator iter1, iter2, temp;
        for (iter1 = m_ListObserver.begin(), iter2 = m_ListObserver.end(); iter1 != iter2;) {
            temp = iter1; 
            ++iter1;
            delete (*temp);
        }
        m_ListObserver.clear();
    }
    
    // 通知对象改变状态
    void Notify()
    {
        std::cout << "Notify Observers's State\n";
        std::list<Observer*>::iterator iter1, iter2;
        for (iter1 = m_ListObserver.begin(), iter2 = m_ListObserver.end(); 
                iter1 != iter2; ++iter1) { 
            (*iter1)->Update(this);
        }
    }
    
    // 新增对象
    void Attach(Observer *pObserver)
    {
        std::cout << "Attach an Observer\n";
        m_ListObserver.push_back(pObserver);
    }
    
    // 删除对象
    void Detach(Observer *pObserver)
    {
        std::list<Observer*>::iterator iter;
        iter = std::find(m_ListObserver.begin(), m_ListObserver.end(), pObserver);
        if (m_ListObserver.end() != iter) {
            m_ListObserver.erase(iter); 
        }
        std::cout << "Detach an Observer\n";
    }
    
    // 虚函数,提供默认的实现,派生类可以自己实现来覆盖基类的实现 
    // 设置状态
    virtual void SetState(STATE nState)
    {
        std::cout << "SetState By Subject\n";
        m_nSubjectState = nState;
    }

    // 得到状态 
    virtual STATE GetState()
    {
        std::cout << "GetState By Subject\n";
        return m_nSubjectState;
    }

protected:
    STATE m_nSubjectState; // 模拟保存 Subject 状态的变量
    std::list<Observer*> m_ListObserver; // 保存 Observer 指针的链表
};

// ConcreateSubject 类,派生在 Subject 类 
class ConcreateSubject : public OSubject 
{
public:
    ConcreateSubject() : OSubject() {} 
    virtual ~ConcreateSubject() {}
    
    // 派生类自己实现来覆盖基类的实现
    virtual void SetState(STATE nState)
    {
        std::cout << "SetState By ConcreateSubject\n"; 
        m_nSubjectState = nState;
    }

    // 得到状态
    virtual STATE GetState() 
    {
        std::cout << "GetState By ConcreateSubject\n";
        return m_nSubjectState;
    }
};

// ConcreateObserver 类派生自 Observer 
class ConcreateObserver : public Observer 
{
public:
    ConcreateObserver() : Observer() {} 
    virtual ~ConcreateObserver() {}
    
    // 虚函数,实现基类提供的接口
    virtual void Update(OSubject* pSubject)
    {
        if (NULL == pSubject) return;
        m_nObserverState = pSubject->GetState();
        std::cout << "The ObeserverState is " << m_nObserverState << std::endl; 
    }
};


void testObserver(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testObserver start--------------------------------"<<std::endl;
    
    Observer *p1 = new ConcreateObserver;
    Observer *p2 = new ConcreateObserver;
    OSubject *p = new ConcreateSubject; 
    
    p->Attach(p1);
    p->Attach(p2);
    p->SetState(4);
    p->Notify();
    p->Detach(p1); 
    p->SetState(10); 
    p->Notify();
    
    delete p;

    std::cout<<"---------------------------testObserver end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !OBSERVER_HPP */
