/*
 * Singleton.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
保证一个类仅有一个实例，并提供一个访问它的全局访问点。
*/

/*
解析:
Singleton模式其实是对全局静态变量的一个取代策略,上面提到的Singleton模式的两个作用在C++中是通过如下的机制实现的:
1)仅有一个实例,提供一个类的静态成员变量,大家知道类的静态成员变量对于一个类的所有对象而言是惟一的 
2)提供一个访问它的全局访问点,也就是提供对应的访问这个静态成员变量的静态成员函数,对类的所有对象而言也是惟一的.
在 C++中,可以直接使用类域进行访问而不必初始化一个类的对象.
*/

NAMESPACE_START

class Singleton 
{
public:
    Singleton(){};
    ~Singleton(){};
    
    // 静态成员函数,提供全局访问的接口 
    static Singleton* GetInstancePtr()
    {
        if (NULL == m_pStatic) {
            m_pStatic = new Singleton(); 
        }
        return m_pStatic;
    } 
    static Singleton GetInstance()
    {
        return *GetInstancePtr();
    }

    void Test()
    {
        std::cout << "Test!\n";
    }

private:
    // 静态成员变量,提供全局惟一的一个实例 
    static Singleton *m_pStatic;
};

// 类的静态成员变量要在类体外进行定义
Singleton* Singleton::m_pStatic = NULL;


void testSingleton(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testSingleton start--------------------------------"<<std::endl;
    
    // 不用初始化类对象就可以访问了 
    Singleton::GetInstancePtr()->Test();
    Singleton::GetInstance().Test();
    
    std::cout<<"---------------------------testSingleton end--------------------------------"<<std::endl;
}

NAMESPACE_END


#endif /* !SINGLETON_HPP */
