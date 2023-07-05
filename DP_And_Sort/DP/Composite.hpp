/*
 * Composite.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include "Macros.h"

/*
作用:
将对象组合成树形结构以表示“部分-整体”的层次结构。
Composite使得用户对单个对象和组合对象的使用具有一致性。
*/

/*
抽象基类: 
1)Component:为组合中的对象声明接口,声明了类共有接口的缺省行为(如这里的 Add,Remove,GetChild 函数),声明一个接口函数可以访问 Component 的子组件.

接口函数: 
1)Component::Operatation:定义了各个组件共有的行为接口,由各个组件的具体实现.
2)Component::Add添加一个子组件
3)Component::Remove::删除一个子组件.
4)Component::GetChild:获得子组件的指针.

解析:
Component 模式是为解决组件之间的递归组合提供了解决的办法,它主要分为两个派生类,
其中的 Leaf 是叶子结点,也就是不含有子组件的结点,而 Composite 是含有子组件的类.
举一个例子来说明这个模式,在 UI 的设计中,最基本的控件是诸如 Button,Edit 这样的控件,
相当于是这里的 Leaf 组件,而比较复杂的控件比如 List 则可也看做是由这些基本的组件组合起来的控件,
相当于这里的 Composite,它们之间有一些行为含义是相同的,比如在控件上作一个点击,移动操作等等的,
这些都可以定义为抽象基类中的接口虚函数,由各个派生类去实现之,这些都会有的行为就是这里的 Operation 函数,
而添加,删除等进行组件组合的操作只有非叶子结点才可能有,所以虚拟基类中只是提供接口而且默认的实现是什么都不做.
*/

NAMESPACE_START

// 组合中的抽象基类 
class Component
{ 
public:
    Component() {}
    virtual ~Component() {}
    // 纯虚函数,只提供接口,没有默认的实现 
    virtual void Operation() = 0;

    // 虚函数,提供接口,有默认的实现就是什么都不做
    virtual void Add(Component *pChild) {} 
    virtual void Remove(Component *pChild) {}
    virtual Component* GetChild(int nIndex) { return NULL;}
};

// 派生自 Component,是其中的叶子组件的基类 
class Leaf : public Component 
{
public: 
    Leaf() 
    {
        std::cout << "construction by leaf\n";
    }

    virtual ~Leaf() 
    {
        std::cout << "destruction by leaf\n";
    } 

    virtual void Operation()
    {
        std::cout << "Operation by leaf\n";
    }
};

// 派生自 Component,是其中的含有子件的组件的基类 
class Composite : public Component 
{
public: 
    Composite() 
    {
        std::cout << "construction by Composite\n";
    }
    virtual ~Composite()
    {
        std::list<Component *>::iterator iter1, iter2, temp;
        for (iter1 = m_ListOfComponent.begin(), 
                iter2 = m_ListOfComponent.end(); 
                iter1 != iter2;) {
            temp = iter1; ++iter1;
            delete (*temp);
        }
        std::cout << "destruction by Composite\n";
    }

    virtual void Operation()
    {
        std::cout << "Operation by Composite\n";
        std::list<Component *>::iterator iter1, iter2;
        for (iter1 = m_ListOfComponent.begin(), iter2 = m_ListOfComponent.end(); 
                iter1 != iter2; ++iter1) {
            (*iter1)->Operation();
        }
    }

    virtual void Add(Component *pChild)
    {
        m_ListOfComponent.push_back(pChild);
    }

    virtual void Remove(Component *pChild)
    {
        std::list<Component*>::iterator iter;
        iter = find(m_ListOfComponent.begin(), m_ListOfComponent.end(), pChild);
        if (m_ListOfComponent.end() != iter) {
            m_ListOfComponent.erase(iter); 
        }
    }

    virtual Component* GetChild(int nIndex)
    {
        if (nIndex <= 0 || nIndex > m_ListOfComponent.size()) return NULL;

        std::list<Component *>::iterator iter1, iter2;
        int i;
        for (i = 1, iter1 = m_ListOfComponent.begin(), iter2 = m_ListOfComponent.end();
                iter1 != iter2; ++iter1, ++i) {
            if (i == nIndex) break;
        }
        return *iter1;
    }

private:
    // 采用 list 容器去保存子组件 
    std::list<Component*> m_ListOfComponent;
};

void testComposite(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testComposite start--------------------------------"<<std::endl;
    
    Leaf *pLeaf1 = new Leaf(); 
    Leaf *pLeaf2 = new Leaf();

    Composite *pComposite = new Composite; 
    pComposite->Add(pLeaf1); 
    pComposite->Add(pLeaf2); 

    pComposite->Operation();

    pComposite->GetChild(2)->Operation();

    delete pComposite;
    
    std::cout<<"---------------------------testComposite end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !COMPOSITE_HPP */
