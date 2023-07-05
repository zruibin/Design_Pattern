/*
 * BubbleSort.h
 *
 * Created by zhouruibin734 on 2020/08/11.
 * Copyright (c) 2020年 zhouruibin734 All rights reserved.
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Macros.h"
#include <iostream>
#include <vector>

/*
冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，
如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进行直到没有再需要交换，
也就是说该数列已经排序完成。
这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。
*/

/*
1、比较相邻的元素。如果第一个比第二个大，就交换它们两个；
2、对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
3、针对所有的元素重复以上的步骤，除了最后一个；
4、重复步骤1~3，直到排序完成。
*/

/*
时间复杂度(平均)：O(n^2)
时间复杂度(最坏)：O(n^2)
时间复杂度(最好)：O(n)
空间复杂度:O(1)
稳定性：稳定
*/

NAMESPACE_START
void testBubbleSort(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testBubbleSort start--------------------------------"<<std::endl;

    std::vector<int> arr = {2,1,7,55,8,22,0,8,44,32,65,76,97,21,11};
    SPACE::print(arr);

    int length = arr.size();
    for (int i = 0; i < length -1; ++i) {
        for (int j = 0; j < length - i; j++) {
            if (arr[j] > arr[j+1]) { // 相邻元素两两对比
                // 元素交换
                int temp = arr[j+1]; 
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    SPACE::print(arr);
    std::cout<<"---------------------------testBubbleSort end--------------------------------"<<std::endl;
}
NAMESPACE_END


#endif /* !BUBBLESORT_H */
