/*
 * Visitor.hpp
 *
 * Created by Ruibin.Chow on 2020/08/18.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef VISITOR_HPP
#define VISITOR_HPP

#include <iostream>
#include "Macros.h"


NAMESPACE_START

class ConcreateElementA;
class ConcreateElementB;

class Visitor
{
public:
    virtual ~Visitor(){}
    virtual void VisitConcreateElementA(ConcreateElementA *pConcreateElementA) = 0;
    virtual void VisitConcreateElementB(ConcreateElementB *pConcreateElementB) = 0;
protected: 
    Visitor(){}
};

class ConcreateVisitorA : public Visitor
{ 
public:
    virtual ~ConcreateVisitorA() {}
    virtual void VisitConcreateElementA(ConcreateElementA *pConcreateElementA)
    {
        std::cout << "VisitConcreateElementA By ConcreateVisitorA\n";
    }
    virtual void VisitConcreateElementB(ConcreateElementB *pConcreateElementB)
    {
        std::cout << "VisitConcreateElementB By ConcreateVisitorA\n";
    }
};

class ConcreateVisitorB : public Visitor
{ 
public:
    virtual ~ConcreateVisitorB() {}
    virtual void VisitConcreateElementA(ConcreateElementA *pConcreateElementA)
    {
        std::cout << "VisitConcreateElementA By ConcreateVisitorB\n";
    }
    virtual void VisitConcreateElementB(ConcreateElementB *pConcreateElementB)
    {
        std::cout << "VisitConcreateElementB By ConcreateVisitorB\n";
    }
};

class Element 
{
public:
    virtual ~Element(){}
    virtual void Accept(Visitor &rVisitor) = 0;
    protected: Element(){}
};

class ConcreateElementA : public Element
{ 
public:
    virtual ~ConcreateElementA() {} 
    virtual void Accept(Visitor &rVisitor)
    {
        rVisitor.VisitConcreateElementA(this);
    }
};

class ConcreateElementB : public Element
{ 
public:
    virtual ~ConcreateElementB() {} 
    virtual void Accept(Visitor &rVisitor)
    {
        rVisitor.VisitConcreateElementB(this);
    }
};



void testVisitor(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testVisitor start--------------------------------"<<std::endl;
    
    Visitor *pVisitorA = new ConcreateVisitorA(); 
    Element *pElement = new ConcreateElementA();
    pElement->Accept(*pVisitorA);
    
    delete pElement; 
    delete pVisitorA;

    std::cout<<"---------------------------testVisitor end--------------------------------"<<std::endl;
}

NAMESPACE_END

#endif /* !VISITOR_HPP */
