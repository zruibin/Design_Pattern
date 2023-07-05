/*
 * Decorator.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef DECORATOR_HPP
#define DECORATOR_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
动态地给一个对象添加一些额外的职责。就增加功能来说，Decorator 模式相比生成子类更为灵活。
*/

/*
抽象基类: 
1)Component:定义一个对象接口,可以为这个接口动态的添加职责. 
2)Decorator:维持一个指向 Component 的指针,并且有一个和 Component 一致的接口函数.

接口函数:
1)Component::Operation:这个接口函数由 Component 声明,因此 Compo nent 的派生类都需要实现,可以在这个接口函数的基础上给它动态添加职责.

解析:
Decorator 的派生类可以为 ConcreateComponent 类的对象动态的添加职责, 或者可以这么说:Decorator 的派生类装饰 ConcreateComponent 类的对象.
具体是这么实现的,首先初始化一个 ConcreateComponent 类的对象(被装饰 者),采用这个对象去生成一个 Decorator 对象(装饰者),之后对 Operation 函数的调用则是对这个 Decorator 对象成员函数的多态调用.这里的实现要点是 Decorator 类和 ConcreateComponent 类都继承自 Component,从而两者的接口函数是一致的;
其次,Decorator 维护了一个指向 Component 的指针,从而可以实现对 Component::Operation 函数的动态调用.
*/

NAMESPACE_START

// 抽象基类,定义一个对象接口,可以为这个接口动态的添加职责. 
class DComponent
{ 
public:
    DComponent(){}
    virtual ~DComponent(){}
    // 纯虚函数,由派生类实现
    virtual void Operation() = 0; 
};

// 抽象基类,维护一个指向 Component 对象的指针 
class Decorator : public DComponent 
{
public:
    Decorator(DComponent* pComponent) : m_pComponent(pComponent) {}

    virtual ~Decorator()
    {
        delete m_pComponent;
        m_pComponent = NULL;
    }
protected:
    DComponent* m_pComponent;
};

// 派生自 Component,在这里表示需要给它动态添加职责的类 
class ConcreateComponent : public DComponent 
{
public:
    ConcreateComponent() {}
    virtual ~ConcreateComponent() {}
    virtual void Operation()
    {
        std::cout << "Operation of ConcreateComponent\n";
    }
};

// 派生自 Decorator,这里代表为 ConcreateComponent 动态添加职责的类 
class ConcreateDecorator : public Decorator 
{
public:
    ConcreateDecorator(DComponent* pComponent) : Decorator(pComponent) {} 
    virtual ~ConcreateDecorator() {}

    virtual void Operation()
    {
        m_pComponent->Operation();
        this->AddedBehavior();
    }
private:
    void AddedBehavior()
    {
        std::cout << "AddedBehavior of ConcreateDecorator\n";
    }
};


void testDecorator(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testDecorator start--------------------------------"<<std::endl;
    
    // 初始化一个 Component 对象
    DComponent* pComponent = new ConcreateComponent(); 
    // 采用这个 Component 对象去初始化一个 Decorator 对象,
    // 这样就可以为这个 Component 对象动态添加职责
    Decorator* pDecorator = new ConcreateDecorator(pComponent); 
    pDecorator->Operation();
    
    delete pDecorator;
    
    std::cout<<"---------------------------testDecorator end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !DECORATOR_HPP */
