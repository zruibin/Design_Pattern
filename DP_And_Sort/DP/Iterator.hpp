/*
 * Iterator.hpp
 *
 * Created by Ruibin.Chow on 2020/08/18.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include "Macros.h"

/*
作用: 
提供一种方法顺序访问一个聚合对象中各个元素,,而又不需暴露该对象的内部表示.
*/

/*
解析:
Iterator几乎是大部分人在初学C++的时候就无意之中接触到的第一种设计模式,
因为在STL之中,所有的容器类都有与之相关的迭代器.
以前初学STL的时候,时常在看到讲述迭代器作用的时候是这么说的:提供一种方式,
使得算法和容器可以独立的变化,而且在访问容器对象的时候不必暴露容器的内部细节,
具体是怎么做到这一点的呢?在STL的实现中,所有的迭代器(Iterator)都必须遵照一套规范,
这套规范里面定义了几种类型的名称,比如对象的名称,指向对象的指针的名称,指向对象的引用的名称....等等,
当新生成一个容器的时候与之对应的Iterator都要遵守这个规范里面所定义的名称,
这样在外部看来虽然里面的实现细节不一样,但是作用(也就是对外的表象)都是一样的,
通过某个名称可以得到容器包含的对象,通过某个名称可以得到容器包含的对象的指针等等的.
而且,采用这个模式把访问容器的重任都交给了具体的iterator类中.
于是,在使用Iterator来访问容器对象的算法不需要知道需要处理的是什么容器,
只需要遵守事先约定好的Iterator的规范就可以了;而对于各个容器类而言,不管内部的事先如何, 
是树还是链表还是数组,只需要对外的接口也遵守Iterator的标准,
这样算法(Iterator的使用者)和容器(Iterator的提供者)就能很好的进行合作,而且不必关心对方是如何事先的,
简而言之,Iterator就是算法和容器之间的一座桥梁.

在下面的实现中,抽象基类Iterator可以看做是前面提到的Iterator的规范,
它提供了所有Iterator需要遵守的规范也就是对外的接口,
而它的派生类ConcreateIterator则是ConcreateAggregate容器的迭代器,
它遵照这个规范对容器进行迭代和访问操作.
*/

NAMESPACE_START

class Iterater;

// 容器的抽象基类 
class Aggregate
{ 
public:
    virtual ~Aggregate() {}
    virtual Iterater* CreateIterater(Aggregate *pAggregate) = 0; 
    virtual int GetSize() = 0;
    virtual int GetItem(int nIndex) = 0;
};

// 迭代器的抽象基类 
class Iterater
{ 
public:
    Iterater() {}
    virtual ~Iterater() {}
    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual int CurrentItem() = 0;
};

// 一个具体的容器类,这里是用数组表示 
class ConcreateAggregate : public Aggregate 
{
public:
    ConcreateAggregate(int nSize) : m_nSize(nSize), m_pData(nullptr)
    {
        m_pData = new int[m_nSize];
        for (int i = 0; i < nSize; ++i) {
            m_pData[i] = i; 
        }
    }

    virtual ~ConcreateAggregate()
    {
        delete [] m_pData;
        m_pData = NULL;
    }

    virtual Iterater* CreateIterater(Aggregate *pAggregate);

    virtual int GetSize()
    {
        return m_nSize;
    }
    
    virtual int GetItem(int nIndex)
    {
        if (nIndex < m_nSize) {
            return m_pData[nIndex]; 
        } else {
            return -1;
        }
    }

private:
    int m_nSize; 
    int *m_pData;
};

// 访问 ConcreateAggregate 容器类的迭代器类 
class ConcreateIterater : public Iterater
{ 
public:
    ConcreateIterater(Aggregate* pAggregate) : m_pConcreateAggregate(pAggregate), 
                                                m_nIndex(0) {}
    virtual ~ConcreateIterater() {}
    
    virtual void First()
    {
        m_nIndex = 0;
    }

    virtual void Next()
    {
        if (m_nIndex < m_pConcreateAggregate->GetSize()) {
            ++m_nIndex;
        }
    }

    virtual bool IsDone()
    {
        return m_nIndex == m_pConcreateAggregate->GetSize();
    }

    virtual int CurrentItem()
    {
        return m_pConcreateAggregate->GetItem(m_nIndex);
    }

private:
    Aggregate *m_pConcreateAggregate; 
    int m_nIndex;
};


Iterater* ConcreateAggregate::CreateIterater(Aggregate *pAggregate)
{
    return new ConcreateIterater(this);
}



void testIterator(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testIterator start--------------------------------"<<std::endl;

    Aggregate* pAggregate = new ConcreateAggregate(4); 
    Iterater* pIterater = new ConcreateIterater(pAggregate);

    for (; false == pIterater->IsDone(); pIterater->Next()) {
        std::cout << pIterater->CurrentItem() << std::endl; 
    }
    
    std::cout<<"---------------------------testIterator end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !ITERATOR_HPP */
