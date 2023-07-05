/*
 * Features.hpp
 *
 * Created by Ruibin.Chow on 2020/08/17.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef FEATURES_HPP
#define FEATURES_HPP

/*
g++ --std=c++11 -o main main.cc

http://acm2014.cct.lsu.edu/localdoc/cppreference/en/cpp/memory.html
https://www.veaxen.com/c11%E6%99%BA%E8%83%BD%E6%8C%87%E9%92%88%E4%B8%ADmake_shared%E5%AD%98%E5%9C%A8%E7%9A%84%E5%BF%85%E8%A6%81%E6%80%A7.html
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>

class B 
{
public:
   virtual void f(int) {std::cout << "B::f"<< std::endl;}
};
 
class D : public B
{
public:
   virtual void f(int) override //final 
   {std::cout << "D::f"<< std::endl;}
};
 
class F : public D
{
public:
   virtual void f(int) override {std::cout << "F::f"<< std::endl;}
};


void testFeatures(void)
{
    std::cout<<"-----------------------------auto---------------------------------"<<std::endl;
    auto i = 42;
    std::cout<<i<<std::endl;

    std::cout<<"-----------------------------nullptr---------------------------------"<<std::endl;

    int* p1 = NULL;
    int* p2 = nullptr;   
    if(p1 == p2) {
        std::cout<<"p1==p2"<<std::endl;
    }

    std::cout<<"-----------------------Range-based for loops （基于范围的for循环）--------------------------"<<std::endl;

    std::map<std::string, std::vector<int> > map;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    map["one"] = v;
    
    for(const auto& kvp : map) {
        std::cout << kvp.first << std::endl;

        for(auto v : kvp.second) {
            std::cout << "v:" << v << std::endl;
        }
    }
    
    int arr[] = {1,2,3,4,5};
    for(int& e : arr) {
        std::cout << "arr:" << e << std::endl;
    }

    std::cout<<"----------------------------Override和final--------------------------------"<<std::endl;

    F f;
    f.f(12);

    std::cout<<"---------------------Strongly-typed enums 强类型枚举-------------------------"<<std::endl;

    enum class Options {None, One, All};
    Options o = Options::All;

    std::cout<<"-------------------------unique_ptr-------------------------------"<<std::endl;

    std::unique_ptr<int> uniquePtr1(new int(42));
    std::unique_ptr<int> uniquePtr2 = std::move(uniquePtr1); 
    // transfer ownership
    
    if(uniquePtr1)
    std::cout << *(uniquePtr1.get()) << std::endl;
    
    (*uniquePtr2)++;
    
    if(uniquePtr2)
    std::cout << *(uniquePtr2.get()) << std::endl;

    std::cout<<"--------------------------shared_ptr------------------------------"<<std::endl;

    std::shared_ptr<int> sharedPtr1(new int(10));
    std::shared_ptr<int> sharedPtr2 = sharedPtr1;

    ++(*sharedPtr1);

    std::cout << *(sharedPtr2.get()) << std::endl;

    auto sharedPtr3 = std::make_shared<int>(100);
    std::cout << *(sharedPtr3.get()) << std::endl;
    /*
    make_shared<T>是一个非成员函数，使用它的好处是可以一次性分配共享对象和智能指针自身的内存。
    而显示地使用shared_ptr构造函数来构造则至少需要两次内存分配。除了会产生额外的开销，还可能会导致内存泄漏。
    */

    std::cout<<"---------------------------weak_ptr-------------------------------"<<std::endl;

    auto makeSharedPtr = std::make_shared<int>(22);
    std::weak_ptr<int> weakPtr = makeSharedPtr;
    
    {
        auto sharedPtrFormWeak = weakPtr.lock();
        std::cout << "sharedPtrFormWeak:" << *sharedPtrFormWeak << std::endl;
    }
    
    makeSharedPtr.reset();
 
    if(weakPtr.expired()) {
        std::cout << "expired"<< std::endl;
    }
    /*如果你试图锁定(lock)一个过期（指被弱引用对象已经被释放）的weak_ptr，那你将获得一个空的shared_ptr.*/

    std::cout<<"---------------------------lambda--------------------------------"<<std::endl;

    std::vector<int> lambdaV;
    lambdaV.push_back(1);
    lambdaV.push_back(2);
    lambdaV.push_back(3);
    
    std::for_each(std::begin(lambdaV), std::end(lambdaV), [](int n) {std::cout << n << std::endl;});
    
    auto is_odd = [](int n) {return n%2==1;};
    auto pos = std::find_if(std::begin(lambdaV), std::end(lambdaV), is_odd);
    if(pos != std::end(lambdaV))
        std::cout << *pos << std::endl;

    std::cout<<"---------------------------static_assert--------------------------------"<<std::endl;

    // int size = 4;
    // static_assert(size < 3, "Size is too small");
}

#endif /* !FEATURES_HPP */
