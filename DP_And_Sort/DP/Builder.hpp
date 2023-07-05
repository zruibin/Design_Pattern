/*
 * Builder.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
*/

/*
适用于以下情况: 
1)当创建复杂对象的算法应该独立于该对象的组成部分以及它们的装配方式时。
2)当构造过程必须允许被构造的对象有不同的表示时。

抽象基类: 
1)Builder:这个基类是全部创建对象过程的抽象,提供构建不同组成部分的接口函数

接口: 
1)Builder::BuildPartA,Builder::BuildPartB:是对一个对象不同部分的构建 函数接口,Builder的派生类来具体实现.
另外还有一个需要注意的函数,就是 Director::Construct 函数,这个函数里面 通过调用上面的两个接口函数完成对象的构建--也就是说各个不同部分装配的过程都是一致的(同样的调用的Construct 函数),但是不同的构建方式会有不同 的表示(根据 Builder 的实际类型来决定如何构建,也就是多态)

解析:
Builder 模式是基于这样的一个情况:一个对象可能有不同的组成部分,这几个部 分的不同的创建对象会有不同的表示,但是各个部分之间装配的方式是一致的. 比方说一辆单车,都是由车轮车座等等的构成的(一个对象不同的组成部分),不 同的品牌生产出来的也不一样(不同的构建方式).虽然不同的品牌构建出来的单车不同,但是构建的过程还是一样的(哦,你见过车轮长在车座上的么?). 也就是说,Director::Construct 函数中固定了各个组成部分的装配方式,而具体 是装配怎样的组成部分由 Builder 的派生类实现.

实现:
Builder 模式的实现基于以下几个面向对象的设计原则:
1)把变化的部分提取出来形成一个基类和对应的接口函数,在这里不会变化的是都会创建 PartA 和 PartB,变化的则是不同的创建方法,于是就抽取出这里的Builder基类和 BuildPart A,BuildPartB 接口函数
2)采用聚合的方式聚合了会发生变化的基类,就是这里Director聚合了Builder类的指针.
*/

NAMESPACE_START

// 虚拟基类,是所有 Builder 的基类,提供不同部分的构建接口函数 
class Builder
{ 
public:
    Builder() {} ;
    virtual ~ Builder() {}

    // 纯虚函数,提供构建不同部分的构建接口函数 
    virtual void BuilderPartA() = 0 ; 
    virtual void BuilderPartB() = 0 ;
};

// Builder的派生类,实现BuilderPartA和BuilderPartB接口函数 
class ConcreateBuilder1 : public Builder 
{
public: 
    ConcreateBuilder1() {}
    virtual ~ ConcreateBuilder1() {}
    
    virtual void BuilderPartA()
    {
        std::cout << "BuilderPartA by ConcreateBuilder1\n";
    }
    virtual void BuilderPartB()
    {
        std::cout << "BuilderPartB by ConcreateBuilder1\n";
    }
};

// Builder的派生类,实现BuilderPartA和BuilderPartB接口函数 
class ConcreateBuilder2 : public Builder 
{
public: 
    ConcreateBuilder2() {}
    virtual ~ ConcreateBuilder2() {}
    
    virtual void BuilderPartA()
    {
        std::cout << "BuilderPartA by ConcreateBuilder2\n";
    }
    virtual void BuilderPartB()
    {
        std::cout << "BuilderPartB by ConcreateBuilder2\n";
    }
};

// 使用 Builder 构建产品,构建产品的过程都一致,但是不同的 builder 有不同的实现
// 这个不同的实现通过不同的 Builder 派生类来实现,存有一个 Builder 的指针,通过这个来 实现多态调用
class Director 
{
public:
    Director(Builder * pBuilder) : m_pBuilder(pBuilder) {}

    virtual ~Director()
    {
        delete m_pBuilder;
        m_pBuilder = NULL;
    }

    void Construct()
    {
        m_pBuilder -> BuilderPartA(); 
        m_pBuilder -> BuilderPartB();
    }

private:
    Builder * m_pBuilder;
};

void testBuilder(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testBuilder start--------------------------------"<<std::endl;
    
    Builder *pBuilder1 = new ConcreateBuilder1; 
    Director *pDirector1 = new Director(pBuilder1); 
    pDirector1->Construct();

    Builder *pBuilder2 = new ConcreateBuilder2; 
    Director *pDirector2 = new Director(pBuilder2); 
    pDirector2->Construct();

    delete pDirector1;
    delete pDirector2;

    std::cout<<"---------------------------testBuilder end--------------------------------"<<std::endl;
}

NAMESPACE_END


#endif /* !BUILDER_HPP */
