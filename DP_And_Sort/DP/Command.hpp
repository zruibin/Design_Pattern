/*
 * Command.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include "Macros.h"

/*
作用: 
将一个请求封装为一个对象,从而使你可用不同的请求对客户进行参数化;对请求排队或记录请求日志,以及支持可撤消的操作.
*/

/*
解析:
Comnand 模式的思想是把命令封装在一个类中,就是这里的 Command 基类, 同时把接收对象也封装在一个类中就是这里的 Receiver 类中,由调用这个命令的类也就是这里的 Invoker 类来调用.
其实,如果弄清楚了 Command 模式的原 理,就会发现其实它和注册回调函数的原理是很相似的,而在面向过程的设计中的回调函数其实和这里的 Command 类的作用是一致的.
采用 Command 模式 解耦了命令的发出者和命令的执行者.
*/

NAMESPACE_START

class Command 
{
public:
    virtual ~Command() {}
    virtual void Execute() = 0; 
};

class Receiver 
{
public:
    void Action()
    {
        std::cout << "Receiver Action\n";
    }
};

class Invoker 
{
public:
    Invoker(Command *pCommand) : m_pCommand(pCommand) {}

    ~Invoker()
    {
        delete m_pCommand;
        m_pCommand = NULL;
    }

    void Invoke()
    {
        if (NULL != m_pCommand) {
            m_pCommand->Execute(); 
        }
    }

private:
    Command *m_pCommand; 
};

class ConcreateComand : public Command
{ 
public:
    ConcreateComand(Receiver* pReceiver) : m_pReceiver(pReceiver) {}

    virtual ~ConcreateComand()
    {
        delete m_pReceiver;
        m_pReceiver = NULL;
    }

    virtual void Execute()
    {
        if (NULL != m_pReceiver) {
            m_pReceiver->Action(); 
        }
        std::cout << "Execute by ConcreateComand\n";
    }

private:
    Receiver* m_pReceiver;
};


void testCommand(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testCommand start--------------------------------"<<std::endl;
    
    Receiver *pReceiver = new Receiver();
    Command *pCommand = new ConcreateComand(pReceiver); 
    Invoker *pInvoker = new Invoker(pCommand);
    pInvoker->Invoke(); 
    delete pInvoker;

    std::cout<<"---------------------------testCommand end--------------------------------"<<std::endl;
}

NAMESPACE_END



#endif /* !COMMAND_HPP */
