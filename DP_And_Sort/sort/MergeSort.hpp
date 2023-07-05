/*
 * MergeSort.hpp
 *
 * Created by Ruibin.Chow on 2020/08/13.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <math.h>
#include <iostream>
#include <vector>
#include "Macros.h"


/*
归并排序是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。
若将两个有序表合并成一个有序表，称为2-路归并。
*/

/*
1、把长度为n的输入序列分成两个长度为n/2的子序列；
2、对这两个子序列分别采用归并排序；
3、将两个排序好的子序列合并成一个最终的排序序列。
*/

/*
时间复杂度(平均)：O(nlog2n)
时间复杂度(最坏)：O(nlog2n)
时间复杂度(最好)：O(nlog2n)
空间复杂度:O(n)
稳定性：稳定
*/

/*
归并排序是一种稳定的排序方法。和选择排序一样，归并排序的性能不受输入数据的影响，
但表现比选择排序好的多，因为始终都是O(nlogn）的时间复杂度。代价是需要额外的内存空间。
*/

NAMESPACE_START

using Vector = std::vector<int>;

Vector mergeSortRecursion(const Vector arr);
Vector merge(const Vector left, const Vector right);


void testMergeSort(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testMergeSort start--------------------------------"<<std::endl;
    Vector arr = {2,1,7,55,8,22,0,8,44,32,65,76,97,21,11};
    std::cout << "arr size: " << arr.size() << std::endl;
    SPACE::print(arr);

    Vector arrRecursion = mergeSortRecursion(arr);
    SPACE::print(arrRecursion);

    std::cout<<"---------------------------testMergeSort end--------------------------------"<<std::endl;
}



Vector mergeSortRecursion(const Vector arr)
{
    int len = arr.size();
    if (len < 2) {
        return arr;
    }

    int mid = floor(len/2);
    std::vector<int>::const_iterator midIterator = arr.begin() + mid;
    Vector left(arr.begin(), midIterator); //分片，前半部分
    Vector right(midIterator, arr.end()); //分片，后半部分
    
    return merge(mergeSortRecursion(left), mergeSortRecursion(right));
}

Vector merge(const Vector left, const Vector right)
{
    Vector result;

    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            result.push_back(left[i]);
            ++i;
        } else {
            result.push_back(right[j]);
            ++j;
        }   
    }
    
    while (i < left.size()) {
        result.push_back(left[i]);
        ++i;
    }

    while (j < right.size()) {
        result.push_back(right[j]);
        ++j;
    }

    return result;
}


NAMESPACE_END

#endif /* !MERGESORT_HPP */
