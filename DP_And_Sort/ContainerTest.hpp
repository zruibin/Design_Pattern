/*
 * ContainerTest.h
 *
 * Created by zhouruibin734 on 2020/08/03.
 * Copyright (c) 2020年 zhouruibin734 All rights reserved.
 */

#ifndef CONTAINERTEST_H
#define CONTAINERTEST_H

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

#include "Macros.h"

void testArray(void);
void testVector(void);
void testDeque(void);
void testForward_list(void);
void testList(void);
void testSet(void);
void testMultiset(void);
void testMap(void);
void testMultimap(void);
void testUnordered_set(void);
void testUnordered_multiset(void);
void testUnordered_map(void);
void testUnordered_multimap(void);
void testStack(void);
void testQueue(void);
void testPriority_queue(void);

void testMainContainer(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testMainContainer start--------------------------------"<<std::endl;
    testArray();
    testVector();
    testDeque();
    testForward_list();
    testList();
    testSet();
    testMultiset();
    testMap();
    testMultimap();
    testUnordered_set();
    testUnordered_multiset();
    testUnordered_map();
    testUnordered_multimap();
    testStack();
    testQueue();
    testPriority_queue();
    std::cout<<'\n';
    std::cout<<"---------------------------testMainContainer end--------------------------------"<<std::endl;
}

void testArray(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testArray start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/array

    std::array<int, 3> a1{1, 2, 3};
    std::array<int, 3> a2 = {1, 2, 3};
    std::array<std::string, 2> a3 = {std::string("a"), "b"};
    
    std::sort(a1.begin(), a1.end());
    std::reverse_copy(a2.begin(), a2.end(), 
                        std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    
    SPACE::print(a3);

    std::cout<<"---------------------------testArray end--------------------------------"<<std::endl;
}

void testVector(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testVector start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/vector

    std::vector<int> v1 = {1, 3, 5, 7};

    v1.push_back(6);
    v1.push_back(2);

    v1.at(1) = 10;
    v1[2] = 20;

    SPACE::print(v1);
    std::cout << "size: " << v1.size()
                << " max_size: " << v1.max_size()
                << " capacity: " << v1.capacity()
                << " is_empty: " << v1.empty()
                << std::endl;

    std::cout << "front: " << v1.front() << " back: " << v1.back() << std::endl;

    v1.pop_back();
    SPACE::print(v1);

    v1.erase(v1.begin()+1, v1.begin()+2);
    SPACE::print(v1);

    v1.clear();
    std::cout << "clear -> " << "size: " << v1.size()
                << " max_size: " << v1.max_size()
                << " capacity: " << v1.capacity()
                << " is_empty: " << v1.empty()
                << std::endl;
    
    v1.shrink_to_fit();
    std::cout << "shrink_to_fit -> " << "size: " << v1.size()
                << " max_size: " << v1.max_size()
                << " capacity: " << v1.capacity()
                << " is_empty: " << v1.empty()
                << std::endl;

    std::cout<<"---------------------------testVector end--------------------------------"<<std::endl;   
}

void testDeque(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testDeque start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/deque

    std::deque<int> d1 = {1, 3, 5, 7};

    d1.push_front(11);
    d1.push_back(2);

    d1.at(1) = 10;
    d1[2] = 20;

    SPACE::print(d1);
    std::cout << "size: " << d1.size()
                << " max_size: " << d1.max_size()
                << " is_empty: " << d1.empty()
                << std::endl;

    std::cout << "front: " << d1.front() << " back: " << d1.back() << std::endl;

    d1.pop_back();
    SPACE::print(d1);

    d1.erase(d1.begin()+1, d1.begin()+2);
    SPACE::print(d1);

    d1.clear();
    std::cout << "clear -> " << "size: " << d1.size()
                << " max_size: " << d1.max_size()
                << " is_empty: " << d1.empty()
                << std::endl;
    
    d1.shrink_to_fit();
    std::cout << "shrink_to_fit -> " << "size: " << d1.size()
                << " max_size: " << d1.max_size()
                << " is_empty: " << d1.empty()
                << std::endl;

    std::cout<<"---------------------------testDeque end--------------------------------"<<std::endl;
}

void testForward_list(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testForward_list start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/forward_list
    //实现为单链表

    std::forward_list<int> fl = {1, 1, 3, 5, 7};

    fl.insert_after(fl.begin(), 30);
    fl.push_front(22);

    SPACE::print(fl);
    std::cout << "max_size: " << fl.max_size()
                << " is_empty: " << fl.empty()
                << std::endl;
    std::cout << "front: " << fl.front() << std::endl;

    fl.pop_front();
    SPACE::print(fl);
    std::cout << "max_size: " << fl.max_size()
                << " is_empty: " << fl.empty()
                << std::endl;


    fl.resize(10);
    SPACE::print(fl);

    fl.remove(1); // 移除两个等于 1 的元素
    fl.remove_if([](int n){ return n == 0; }); // 移除全部等于 0 的元素
    SPACE::print(fl);

    fl.clear();
    std::cout << "max_size: " << fl.max_size()
                << " is_empty: " << fl.empty()
                << std::endl;

    std::forward_list<int> list1 = { 5,9,0,1,3 };
    std::forward_list<int> list2 = { 8,7,2,6,4 };
    list1.sort();
    list2.sort();
    SPACE::print(list1);
    SPACE::print(list2);
    list1.merge(list2);
    SPACE::print(list1);

    std::cout<<"---------------------------testForward_list end--------------------------------"<<std::endl;
}

void testList(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testList start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/list
    //不支持快速随机访问。它通常实现为双向链表。
    
    std::list<int> list1 = {1, 1, 3, 5, 7};

    std::cout << "front: " << list1.front() << " back: " << list1.back() << std::endl;

    // 添加整数到 list 开头
    list1.push_front(25);
    // 添加整数到 list 结尾
    list1.push_back(13);
    SPACE::print(list1);

    list1.pop_front();
    list1.pop_back();
    SPACE::print(list1);
    std::cout << "size: " << list1.size()
                << " max_size: " << list1.max_size()
                << " is_empty: " << list1.empty()
                << std::endl;

    auto it = std::find(list1.begin(), list1.end(), 5);
    if (it != list1.end()) {
        list1.insert(it, 42);
    }
    SPACE::print(list1);

    list1.clear();
    std::cout << "size: " << list1.size()
                << " max_size: " << list1.max_size()
                << " is_empty: " << list1.empty()
                << std::endl;

    std::cout<<"---------------------------testList end--------------------------------"<<std::endl;
}

void testSet(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testSet start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/set
    //含有 Key 类型对象的已排序集。用比较函数 比较 (Compare) 进行排序。搜索、移除和插入拥有对数复杂度。 set 通常以红黑树实现。

    std::set<int> set1 = {1, 1, 3, 5, 7};
    SPACE::print(set1);
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << std::endl;
    
    std::set<int>::iterator search = set1.find(5);
    if (search != set1.end()) {
        std::cout << (*search) << std::endl;
        set1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::print(set1);

    set1.insert(33);
    set1.insert(23);
    SPACE::print(set1);

    set1.clear();
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << std::endl;

    std::cout<<"---------------------------testSet end--------------------------------"<<std::endl;
}

void testMultiset(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testMultiset start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/multiset
    //不同于 set ，它允许多个关键拥有等价的值。

    std::multiset<int> set1 = {1, 1, 2, 2, 3, 5, 7};
    SPACE::print(set1);
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << std::endl;
    
    std::set<int>::iterator search = set1.find(5);
    if (search != set1.end()) {
        std::cout << (*search) << std::endl;
        set1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::print(set1);

    set1.insert(33);
    set1.insert(23);
    set1.insert(23);
    SPACE::print(set1);

    set1.clear();
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << std::endl;

    std::cout<<"---------------------------testMultiset end--------------------------------"<<std::endl;
}

void testMap(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testMap start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/map
    //map 通常实现为红黑树。

    std::map<std::string, int> map1 = {
        {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4},
    };

    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << std::endl;

    map1.insert({"5", 5});
    map1["6"] = 6;
    SPACE::printMap(map1);

    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << std::endl;
    
    std::cout << "3 -> " << map1["3"] << std::endl;

    std::map<std::string, int>::iterator search = map1.find("2");
    if (search != map1.end()) {
        std::cout << search->first << " " << search->second << std::endl;
        map1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::printMap(map1);

    map1.clear();
    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << std::endl;

    std::cout<<"---------------------------testMap end--------------------------------"<<std::endl;
}

void testMultimap(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testMultimap start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/multimap
    //含有键值对的已排序列表，同时容许多个元素拥有同一键,拥有等价键的键值对的顺序就是插入顺序，且不会更改。

    std::multimap<std::string, int> map1 = {
        {"1", 1}, {"1", 1}, {"1", 1}, {"2", 2}, {"3", 3}, {"3", 3}, {"4", 4},
    };

    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << std::endl;

    map1.insert({"5", 5});
    // map1["6"] = 6; //不允许
    SPACE::printMap(map1);

    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << std::endl;
    
    // std::cout << "3 -> " << map1["3"] << std::endl; //不允许通过key访问

    std::map<std::string, int>::iterator search = map1.find("2");
    if (search != map1.end()) {
        std::cout << search->first << " " << search->second << std::endl;
        map1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::printMap(map1);

    map1.clear();
    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << std::endl;

    std::cout<<"---------------------------testMultimap end--------------------------------"<<std::endl;
}

void testUnordered_set(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testUnordered_set start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/unordered_set
    /*unordered_set 是含有 Key 类型唯一对象集合的关联容器。搜索、插入和移除拥有平均常数时间复杂度。
        在内部，元素并不以任何特别顺序排序，而是组织进桶中。元素被放进哪个桶完全依赖其值的哈希。
        这允许对单独元素的快速访问，因为哈希一旦确定，就准确指代元素被放入的桶。
        不可修改容器元素（即使通过非 const 迭代器），因为修改可能更改元素的哈希，并破坏容器。
    */
    std::unordered_set<int> set1 = {1, 1, 3, 5, 7};

    SPACE::print(set1);
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << " bucket_count: " << set1.bucket_count()
                << " max_bucket_count: " << set1.max_bucket_count()
                << " load_factor:" << set1.load_factor()
                << " max_load_factor:" << set1.max_load_factor()
                << std::endl;
    
    std::unordered_set<int>::iterator search = set1.find(5);
    if (search != set1.end()) {
        std::cout << (*search) << std::endl;
        set1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::print(set1);

    set1.insert(33);
    set1.insert(23);
    SPACE::print(set1);

    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << " bucket_count: " << set1.bucket_count()
                << " max_bucket_count: " << set1.max_bucket_count()
                << " load_factor:" << set1.load_factor()
                << " max_load_factor:" << set1.max_load_factor()
                << std::endl;

    set1.clear();

    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << " bucket_count: " << set1.bucket_count()
                << " max_bucket_count: " << set1.max_bucket_count()
                << " load_factor:" << set1.load_factor()
                << " max_load_factor:" << set1.max_load_factor()
                << std::endl;

    std::cout<<"---------------------------testUnordered_set end--------------------------------"<<std::endl;
}

void testUnordered_multiset(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testUnordered_multiset start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/unordered_multiset
    /*nordered_multiset 是关联容器，含有可能非唯一 Key 类型对象的集合。搜索、插入和移除拥有平均常数时间复杂度。
        元素在内部并不以任何顺序排序，只是被组织到桶中。
        元素被放入哪个桶完全依赖其值的哈希。这允许快速访问单独的元素，因为一旦计算哈希，它就指代放置该元素的准确的桶。
    */
    std::unordered_multiset<int> set1 = {1, 1, 1, 3, 3, 5, 5, 7};

    SPACE::print(set1);
    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << " bucket_count: " << set1.bucket_count()
                << " max_bucket_count: " << set1.max_bucket_count()
                << " load_factor:" << set1.load_factor()
                << " max_load_factor:" << set1.max_load_factor()
                << std::endl;
    
    std::unordered_set<int>::iterator search = set1.find(5);
    if (search != set1.end()) {
        std::cout << (*search) << std::endl;
        set1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::print(set1);

    set1.insert(33);
    set1.insert(23);
    SPACE::print(set1);

    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << " bucket_count: " << set1.bucket_count()
                << " max_bucket_count: " << set1.max_bucket_count()
                << " load_factor:" << set1.load_factor()
                << " max_load_factor:" << set1.max_load_factor()
                << std::endl;

    set1.clear();

    std::cout << "size: " << set1.size()
                << " max_size: " << set1.max_size()
                << " is_empty: " << set1.empty()
                << " bucket_count: " << set1.bucket_count()
                << " max_bucket_count: " << set1.max_bucket_count()
                << " load_factor:" << set1.load_factor()
                << " max_load_factor:" << set1.max_load_factor()
                << std::endl;

    std::cout<<"---------------------------testUnordered_multiset end--------------------------------"<<std::endl;
}

void testUnordered_map(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testUnordered_map start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/unordered_map
    /*
        unordered_map 是关联容器，含有带唯一键的键-值 pair 。搜索、插入和元素移除拥有平均常数时间复杂度。
        元素在内部不以任何特定顺序排序，而是组织进桶中。
        元素放进哪个桶完全依赖于其键的哈希。这允许对单独元素的快速访问，因为一旦计算哈希，则它准确指代元素所放进的桶。
    */

    std::unordered_map<std::string, int> map1 = {
        {"1", 1}, {"1", 1}, {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4},
    };

    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << " bucket_count: " << map1.bucket_count()
                << " max_bucket_count: " << map1.max_bucket_count()
                << " load_factor:" << map1.load_factor()
                << " max_load_factor:" << map1.max_load_factor()
                << std::endl;

    map1.insert({"5", 5});
    map1["6"] = 6;
    SPACE::printMap(map1);

    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << " bucket_count: " << map1.bucket_count()
                << " max_bucket_count: " << map1.max_bucket_count()
                << " load_factor:" << map1.load_factor()
                << " max_load_factor:" << map1.max_load_factor()
                << std::endl;
    
    std::cout << "3 -> " << map1["3"] << std::endl;

    std::unordered_map<std::string, int>::iterator search = map1.find("2");
    if (search != map1.end()) {
        std::cout << search->first << " " << search->second << std::endl;
        map1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::printMap(map1);

    /*C++20
    if (map1.contains("4")) {
        std::cout << "Found\n";
    } else {
        std::cout << "Not found\n";
    }
    */

    map1.clear();
    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << " bucket_count: " << map1.bucket_count()
                << " max_bucket_count: " << map1.max_bucket_count()
                << " load_factor:" << map1.load_factor()
                << " max_load_factor:" << map1.max_load_factor()
                << std::endl;

    std::cout<<"---------------------------testUnordered_map end--------------------------------"<<std::endl;
}

void testUnordered_multimap(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testUnordered_multimap start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/unordered_multimap
    /*
        unordered_multimap 是无序关联容器，支持等价的关键（一个 unordered_multimap 可含有每个关键值的多个副本）和将关键与另一类型的值关联。 
        unordered_multimap 类支持向前迭代器。搜索、插入和移除拥有平均常数时间复杂度。
        元素在内部不以任何特定顺序排序，而是组织到桶中。
        元素被放进哪个桶完全依赖于其关键的哈希。
        这允许到单独元素的快速访问，因为哈希一旦计算，则它指代元素被放进的准确的桶。
        不要求此容器的迭代顺序稳定    
    */

    std::unordered_multimap<std::string, int> map1 = {
        {"1", 1}, {"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"4", 4}, {"4", 4}
    };

    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << " bucket_count: " << map1.bucket_count()
                << " max_bucket_count: " << map1.max_bucket_count()
                << " load_factor:" << map1.load_factor()
                << " max_load_factor:" << map1.max_load_factor()
                << std::endl;

    map1.insert({"5", 5});
    // map1["6"] = 6; //不允许
    SPACE::printMap(map1);

    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << " bucket_count: " << map1.bucket_count()
                << " max_bucket_count: " << map1.max_bucket_count()
                << " load_factor:" << map1.load_factor()
                << " max_load_factor:" << map1.max_load_factor()
                << std::endl;
    
    // std::cout << "3 -> " << map1["3"] << std::endl; //不通过key允许

    std::unordered_map<std::string, int>::iterator search = map1.find("1");
    if (search != map1.end()) {
        std::cout << search->first << " " << search->second << std::endl;
        map1.erase(search);
    } else {
        std::cout << "Not found\n";
    }
    SPACE::printMap(map1);

    map1.clear();
    std::cout << "size: " << map1.size()
                << " max_size: " << map1.max_size()
                << " is_empty: " << map1.empty()
                << " bucket_count: " << map1.bucket_count()
                << " max_bucket_count: " << map1.max_bucket_count()
                << " load_factor:" << map1.load_factor()
                << " max_load_factor:" << map1.max_load_factor()
                << std::endl;

    std::cout<<"---------------------------testUnordered_multimap end--------------------------------"<<std::endl;
}

void testStack(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testStack start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/stack
    /*
        std::stack 类是容器适配器，它给予程序员栈的功能——特别是 FILO （先进后出）数据结构。
        该类模板表现为底层容器的包装器——只提供特定函数集合。栈从被称作栈顶的容器尾部推弹元素。
        标准容器 std::vector 、 std::deque 和 std::list 满足这些要求。若不为特定的 stack 类特化指定容器类，则使用标准容器 std::deque 。
    */
    std::stack<int, std::vector<int>> stack1;

    std::cout << "size: " << stack1.size()
                << " empty: " << stack1.empty()
                << std::endl;
    
    stack1.push(10);
    stack1.push(11);
    stack1.push(12);

    std::cout << "size: " << stack1.size()
                << " empty: " << stack1.empty()
                << std::endl;

    std::cout << "top: " << stack1.top() << std::endl;

    stack1.pop();

    std::cout << "top: " << stack1.top() << std::endl;
    std::cout << "size: " << stack1.size()
                << " empty: " << stack1.empty()
                << std::endl;

    std::cout<<"---------------------------testStack end--------------------------------"<<std::endl;
}

void testQueue(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testQueue start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/queue
    /*
        std::queue 类是容器适配器，它给予程序员队列的功能——尤其是 FIFO （先进先出）数据结构。
        类模板表现为底层容器的包装器——只提供特定的函数集合。 queue 在底层容器尾端推入元素，从首端弹出元素。
        标准容器 std::deque 和 std::list 满足这些要求。
    */
    std::queue<int, std::list<int>> queue1;

    std::cout << "size: " << queue1.size()
                << " empty: " << queue1.empty()
                << std::endl;

    queue1.push(10);
    queue1.push(11);
    queue1.push(12);
    queue1.push(13);
    queue1.push(14);

    std::cout << "size: " << queue1.size()
                << " empty: " << queue1.empty()
                << std::endl;

    std::cout << "front: " << queue1.front() << " | back: " << queue1.back() << std::endl;

    queue1.pop();
    queue1.pop();

    std::cout << "front: " << queue1.front() << " | back: " << queue1.back() << std::endl;

    std::cout << "size: " << queue1.size()
                << " empty: " << queue1.empty()
                << std::endl;

    std::cout<<"---------------------------testQueue end--------------------------------"<<std::endl;
}

void testPriority_queue(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testPriority_queue start--------------------------------"<<std::endl;
    //https://zh.cppreference.com/w/cpp/container/priority_queue
    /*
        priority_queue 是容器适配器，它提供常数时间的（默认）最大元素查找，对数代价的插入与释出。
        可用用户提供的 Compare 更改顺序，例如，用 std::greater<T> 将导致最小元素作为 top() 出现。
        用 priority_queue 工作类似管理某些随机访问容器中的堆，优势是不可能突然把堆非法化。
    */
    std::priority_queue<int, std::deque<int>> queue1;

    std::cout << "size: " << queue1.size()
                << " empty: " << queue1.empty()
                << std::endl;

    for(int n : {1,8,5,6,3,4,0,9,7,2}) {
        queue1.push(n);
    }

    std::cout << "size: " << queue1.size()
                << " empty: " << queue1.empty()
                << std::endl;
    while(!queue1.empty()) {
        std::cout << queue1.top() << " ";
        queue1.pop();
    } 
    std::cout<<'\n';   

    std::priority_queue<int, std::vector<int>, std::greater<int> > queue2;
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        queue2.push(n);
    while(!queue2.empty()) {
        std::cout << queue2.top() << " ";
        queue2.pop();
    } 
    std::cout<<'\n';  
 
    // 用 lambda 比较元素。
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> queue3(cmp);
    for(int n : {1,8,5,6,3,4,0,9,7,2})
        queue3.push(n);
    while(!queue3.empty()) {
        std::cout << queue3.top() << " ";
        queue3.pop();
    }   
    std::cout<<'\n';

    std::cout<<"---------------------------testPriority_queue end--------------------------------"<<std::endl;
}

#endif /* !CONTAINERTEST_H */
