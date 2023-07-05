/*
 * SelectionSort.hpp
 *
 * Created by Ruibin.Chow on 2020/08/11.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef SELECTION_H
#define SELECTION_H

#include "Macros.h"
#include <iostream>
#include <vector>

/*
选择排序(Selection-sort)是一种简单直观的排序算法。
它的工作原理：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
以此类推，直到所有元素均排序完毕。
*/

/*
n个记录的直接选择排序可经过n-1趟直接选择排序得到有序结果。具体算法描述如下：

1、初始状态：无序区为R[1..n]，有序区为空；
2、第i趟排序(i=1,2,3…n-1)开始时，当前有序区和无序区分别为R[1..i-1]和R(i..n）。
   该趟排序从当前无序区中-选出关键字最小的记录 R[k]，将它与无序区的第1个记录R交换，
   使R[1..i]和R[i+1..n)分别变为记录个数增加1个的新有序区和记录个数减少1个的新无序区；
3、n-1趟结束，数组有序化了。
*/

/*
时间复杂度(平均)：O(n^2)
时间复杂度(最坏)：O(n^2)
时间复杂度(最好)：O(n^2)
空间复杂度:O(1)
稳定性：不稳定
*/

/*
表现最稳定的排序算法之一，因为无论什么数据进去都是O(n2)的时间复杂度，所以用到它的时候，数据规模越小越好。
唯一的好处可能就是不占用额外的内存空间了吧。
理论上讲，选择排序可能也是平时排序一般人想到的最多的排序方法了吧。
*/

NAMESPACE_START
void testSelectionSort(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testSelectionSort start--------------------------------"<<std::endl;

    std::vector<int> arr = {2,1,7,55,8,22,0,8,44,32,65,76,97,21,11};
    SPACE::print(arr);

    int length = arr.size();
    int minIndex, temp;

    for (int i = 0; i < length; i++) {
        minIndex = i;
        for (int j = i+1; j < length; j++) {
            if (arr[j] < arr[minIndex]) { // 寻找最小的数
                minIndex = j; // 将最小数的索引保存
            }
        }
        
        if (minIndex != i) {//下标有变化过才进行交换
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    
    SPACE::print(arr);
    std::cout<<"---------------------------testSelectionSort end--------------------------------"<<std::endl;
}
NAMESPACE_END


#endif /* !SELECTION_H */
