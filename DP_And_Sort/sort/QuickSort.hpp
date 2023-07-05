/*
 * QuickSort.hpp
 *
 * Created by Ruibin.Chow on 2020/08/14.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
#include "Macros.h"

/*
快速排序的基本思想：通过一趟排序将待排记录分隔成独立的两部分，
其中一部分记录的关键字均比另一部分的关键字小，
则可分别对这两部分记录继续进行排序，以达到整个序列有序。
*/

/*
快速排序使用分治法来把一个串（list）分为两个子串（sub-lists）。具体算法描述如下：

1、从数列中挑出一个元素，称为 “基准”（pivot）；
2、重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
   在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
3、递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序。
*/

/*
时间复杂度(平均)：O(nlog2n)
时间复杂度(最坏)：O(n^2)
时间复杂度(最好)：O(nlog2n)
空间复杂度:O(nlog2n)
稳定性：不稳定
*/

/*
递归算法使用的栈由程序自动产生，栈中包含：函数调用时的参数和函数中的局部变量。
如果局部变量很多或者函数内部又调用了其他函数，则栈会很大。
每次递归调用都要操作很大的栈，效率自然会下降。
而对于非递归算法，每次循环使用自己预先创建的栈，因此不管程序复杂度如何，都不会影响程序效率。
*/

NAMESPACE_START

using Vector = std::vector<int>;
using Stack = std::stack<int>;

int partition(Vector &arr, int left, int right);
void quickSortRecursion(Vector &arr, int left, int right);
void quickSortNonRecursion(Vector &arr, int low, int high);


void testQuickSort(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testQuickSort start--------------------------------"<<std::endl;

    Vector arr = {2,1,7,55,8,22,0,8,44,32,65,76,97,21,11,4,0,1001,100};
    Vector arr2(arr);
    std::cout << "arr size: " << arr.size() << std::endl;
    SPACE::print(arr);
    
    clock_t t1 = clock();
    quickSortRecursion(arr, 0, arr.size() - 1);
    SPACE::print(arr);
    clock_t t2 = clock();
    std::cout << "recurcive  " << 1.0*(t2-t1)/CLOCKS_PER_SEC << std::endl;
    
    t1 = clock();
    quickSortNonRecursion(arr2, 0, arr2.size() - 1);
    SPACE::print(arr2);
    t2 = clock();
    std::cout << "none recurcive  " << 1.0*(t2-t1)/CLOCKS_PER_SEC << std::endl;

    std::cout<<"---------------------------testQuickSort end--------------------------------"<<std::endl;
}

/**把数组分为两部分，轴pivot左边的部分都小于轴右边的部分**/
int partition(Vector &arr, int low, int high)
{
    int pivot = arr[low];  //任选元素作为轴，这里选首元素
    while(low < high){
        while(low < high && arr[high] >= pivot)
            high--;
        
        arr[low] = arr[high];
        
        while(low < high && arr[low] <= pivot)
            low++;
        
        arr[high] = arr[low];
    }
    //此时low == high
    arr[low] = pivot;
    return low;
}

void quickSortRecursion(Vector &arr, int low, int high)
{
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSortRecursion(arr, low, pivot-1);
        quickSortRecursion(arr, pivot+1, high);
    }
}

void quickSortNonRecursion(Vector &arr, int low, int high)
{
    Stack st;
    if (low < high) {
        int mid = partition(arr, low, high);
        if (low < mid-1) {
            st.push(low);
            st.push(mid-1);
        }
        
        if (mid + 1 < high) {
            st.push(mid+1);
            st.push(high);
        }
        //其实就是用栈保存每一个待排序子串的首尾元素下标
        //下一次while循环时取出这个范围，对这段子序列进行partition操作
        while (!st.empty()) {
            int q = st.top();
            st.pop();
            int p = st.top();
            st.pop();
            
            mid = partition(arr,p,q);
            
            if (p < mid-1) {
                st.push(p);
                st.push(mid-1);
            }
            
            if (mid+1<q) {
                st.push(mid+1);
                st.push(q);
            }
        }
    }
}

NAMESPACE_END

#endif /* !QUICKSORT_HPP */
