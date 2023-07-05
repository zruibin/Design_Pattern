/*
 * TemplateMethod.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef TEMPLATEMETHOD_HPP
#define TEMPLATEMETHOD_HPP

#include <iostream>
#include "Macros.h"

/*
作用: 定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。
TemplateMethod使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。
*/

/*
抽象基类: 
1)AbstractClass:抽象基类,定义算法的轮廓

解析:
TemplateMethod 的关键在于在基类中定义了一个算法的轮廓,但是算法每一步具体的实现留给了派生类.
但是这样也会造成设计的灵活性不高的缺点,因为轮廓已经定下来了要想改变就比较难了,这也是为什么优先采用聚合而不是继承的原因.
*/

NAMESPACE_START

// 抽象基类,定义算法的轮廓 
class AbstractClass
{
public:
    AbstractClass() {}
    virtual ~AbstractClass() {}

    // 这个函数中定义了算法的轮廓 
    void TemplateMethod()
    {
        PrimitiveOperation1();
        PrimitiveOperation2();
    }
protected:
    // 纯虚函数,由派生类实现之
    virtual void PrimitiveOperation1() = 0; 
    virtual void PrimitiveOperation2() = 0;
};

// 继承自 AbstractClass,实现算法 
class ConcreateClass : public AbstractClass 
{
public:
    ConcreateClass(){}
    virtual ~ConcreateClass() {}
protected:
    virtual void PrimitiveOperation1()
    {
        std::cout << "PrimitiveOperation1 by ConcreateClass\n";
    }

    virtual void PrimitiveOperation2()
    {
        std::cout << "PrimitiveOperation2 by ConcreateClass\n";
    }
};



void testTemplateMethod(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testTemplateMethod start--------------------------------"<<std::endl;
    
    AbstractClass* pConcreateClass = new ConcreateClass; 
    pConcreateClass->TemplateMethod();
    
    delete pConcreateClass;
    
    std::cout<<"---------------------------testTemplateMethod end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !TEMPLATEMETHOD_HPP */
