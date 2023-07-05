/*
 * ShellSort.hpp
 *
 * Created by Ruibin.Chow on 2020/08/12.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef SHELLSORT_HPP
#define SHELLSORT_HPP

#include <math.h>
#include <iostream>
#include <vector>
#include "Macros.h"

/*
1959年Shell发明，第一个突破O(n2)的排序算法，是简单插入排序的改进版。
它与插入排序的不同之处在于，它会优先比较距离较远的元素。希尔排序又叫缩小增量排序。
*/

/*
先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，具体算法描述：

1、选择一个增量序列t1，t2，…，tk，其中ti>tj，tk=1；
2、按增量序列个数k，对序列进行k 趟排序；
3、每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。
   仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
*/

/*
时间复杂度(平均)：O(n^1.3)
时间复杂度(最坏)：O(n^2)
时间复杂度(最好)：O(n)
空间复杂度:O(1)
稳定性：不稳定
*/

/*
希尔排序的核心在于间隔序列的设定。既可以提前设定好间隔序列，也可以动态的定义间隔序列。
动态定义间隔序列的算法是《算法（第4版）》的合著者RobertSedgewick提出的。
*/

NAMESPACE_START
void testShellSort(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testShellSort start--------------------------------"<<std::endl;
    std::vector<int> arr = {2,1,7,55,8,22,0,8,44,32,65,76,97,21,11};
    SPACE::print(arr);

    int len = arr.size();
    for (int gap = floor(len / 2); gap > 0; gap = floor(gap / 2)) {
        for (int i = gap; i < len; i++) {
            int j = i;
            int current = arr[i];
            while (j - gap >= 0 && current < arr[j - gap]) {
                 arr[j] = arr[j - gap];
                 j = j - gap;
            }
            arr[j] = current;
        }
    }

    SPACE::print(arr);
    std::cout<<"---------------------------testShellSort end--------------------------------"<<std::endl;
}
NAMESPACE_END

#endif /* !SHELLSORT_HPP */
