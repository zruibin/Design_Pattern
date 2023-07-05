/*
 * Sort.h
 *
 * Created by zhouruibin734 on 2020/08/11.
 * Copyright (c) 2020年 zhouruibin734 All rights reserved.
 */

#ifndef SORT_H
#define SORT_H

#include "Macros.h"
#include <iostream>
#include "BubbleSort.hpp"
#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "ShellSort.hpp"
#include "MergeSort.hpp"
#include "QuickSort.hpp"
#include "HeapSort.hpp"

NAMESPACE_START
void testSort()
{
    std::cout<<'\n';
    std::cout<<"---------------------------testSort start--------------------------------"<<std::endl;
    
    SPACE::testBubbleSort();
    SPACE::testSelectionSort();
    SPACE::testInsertionSort();
    SPACE::testShellSort();
    SPACE::testMergeSort();
    SPACE::testQuickSort();
    SPACE::testHeapSort();

    /*
        https://www.cnblogs.com/edwinchen/p/4783218.html
        https://www.cnblogs.com/zhangchaoyang/articles/2234815.html
        https://blog.csdn.net/zhao_miao/article/details/82706343
        https://blog.csdn.net/hrn1216/article/details/51465270
    */

    std::cout<<'\n';
    std::cout<<"---------------------------testSort end--------------------------------"<<std::endl;
}
NAMESPACE_END

#endif /* !SORT_H */
