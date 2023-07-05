/*
 * Proxy.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef PROXY_HPP
#define PROXY_HPP

#include <iostream>
#include "Macros.h"

/*
作用:
为其他对象提供一种代理以控制对这个对象的访问。
*/

/*
抽象基类:
1)Subject:定义了 Proxy 和 RealSubject 的公有接口,这样就可以在任何需要使用到 RealSubject 的地方都使用 Proxy.

解析:
Proxy 其实是基于这样一种时常使用到的技术-某个对象直到它真正被使用到的时候才被初始化,在没有使用到的时候就暂时用 Proxy 作一个占位符.
这个模式实现的要点就是 Proxy 和 RealSubject 都继承自 Subject,这样保证了两个的接口都是一致的.
*/

NAMESPACE_START

// 定义了 Proxy 和 RealSubject 的公有接口,
// 这样就可以在任何需要使用到 RealSubject 的地方都使用 Proxy. 
class Subject
{
public:
    Subject(){}
    virtual ~Subject(){}
    virtual void Request() = 0; 
};

// 真正使用的实体 
class RealSubject : public Subject 
{
public: 
    RealSubject()
    {
        std::cout << "Constructing a RealSubject\n";
    }

    virtual ~RealSubject(){}

    virtual void Request()
    {
        std::cout << "Request By RealSubject\n";
    }
};

// 代理类,含有一个指向 RealSubject 对象的指针 
class Proxy : public Subject 
{
public: 
    Proxy() : m_pRealSubject(NULL) 
    {
        std::cout << "Constructing a Proxy\n";
    }

    virtual ~Proxy()
    {
        delete m_pRealSubject; 
        m_pRealSubject = NULL;
    }

    virtual void Request()
    {
        // 需要使用 RealSubject 的时候才去初始化 
        if (NULL == m_pRealSubject) {
            std::cout << "Request By Proxy\n"; 
            m_pRealSubject = new RealSubject();
        }
        m_pRealSubject->Request();
    }
private:
    RealSubject* m_pRealSubject;
};


void testProxy(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testProxy start--------------------------------"<<std::endl;
    
    Subject* pProxy = new Proxy(); 
    pProxy->Request();
    
    delete pProxy;
    
    std::cout<<"---------------------------testProxy end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !PROXY_HPP */
