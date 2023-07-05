/*
 * DP.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef DP_HPP
#define DP_HPP

#include <iostream>
#include "Macros.h"
#include "Factory.hpp"
#include "AbstractFactory.hpp"
#include "Builder.hpp"
#include "Prototype.hpp"
#include "Singleton.hpp"
#include "Adapt.hpp"
#include "Bridge.hpp"
#include "Composite.hpp"
#include "Decorator.hpp"
#include "Proxy.hpp"
#include "TemplateMethod.hpp"
#include "ChainOfResponsibility.hpp"
#include "Flyweight.hpp"
#include "Command.hpp"
#include "Observer.hpp"
#include "Strategy.hpp"
#include "State.hpp"
#include "Iterator.hpp"
#include "Memento.hpp"
#include "Visitor.hpp"

NAMESPACE_START

void testDP(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testDP start--------------------------------"<<std::endl;
    
    SPACE::testFactory();
    SPACE::testAbstractFactory();
    SPACE::testBuilder();
    SPACE::testPrototype();
    SPACE::testSingleton();
    SPACE::testAdapt();
    SPACE::testBridge();
    SPACE::testComposite();
    SPACE::testDecorator();
    SPACE::testProxy();
    SPACE::testTemplateMethod();
    SPACE::testChainOfResponsibility();
    SPACE::testFlyweight();
    SPACE::testCommand();
    SPACE::testObserver();
    SPACE::testStrategy();
    SPACE::testState();
    SPACE::testIterator();
    SPACE::testMemento();
    SPACE::testVisitor();

    std::cout<<'\n';
    std::cout<<"---------------------------testDP end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !DP_HPP */
