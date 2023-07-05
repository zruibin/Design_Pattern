/*
 * InsertionSort.hpp
 *
 * Created by Ruibin.Chow on 2020/08/11.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Macros.h"
#include <iostream>
#include <vector>

/*
插入排序（Insertion-Sort）的算法描述是一种简单直观的排序算法。
它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
*/

/*
一般来说，插入排序都采用in-place在数组上实现。具体算法描述如下：
1、从第一个元素开始，该元素可以认为已经被排序；
2、取出下一个元素，在已经排序的元素序列中从后向前扫描；
3、如果该元素（已排序）大于新元素，将该元素移到下一位置；
4、重复步骤3，直到找到已排序的元素小于或者等于新元素的位置；
5、将新元素插入到该位置后；
6、重复步骤2~5。
*/

/*
时间复杂度(平均)：O(n^2)
时间复杂度(最坏)：O(n^2)
时间复杂度(最好)：O(n)
空间复杂度:O(1)
稳定性：稳定
*/

/*
插入排序在实现上，通常采用in-place排序（即只需用到O(1)的额外空间的排序），因而在从后向前扫描过程中，
需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。
*/

NAMESPACE_START
void testInsertionSort(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testInsertionSort start--------------------------------"<<std::endl;

    std::vector<int> arr = {2,1,7,55,8,22,0,8,44,32,65,76,97,21,11};
    SPACE::print(arr);

    int len = arr.size();
    int preIndex, current;
    for (int i = 1; i < len; i++) {
        preIndex = i - 1;
        current = arr[i];
        while (preIndex >= 0 && arr[preIndex] > current) {
            arr[preIndex + 1] = arr[preIndex];
            preIndex--;
        }
        arr[preIndex + 1] = current;
    }

    SPACE::print(arr);
    std::cout<<"---------------------------testInsertionSort end--------------------------------"<<std::endl;
}
NAMESPACE_END

#endif /* !INSERTIONSORT_H */
