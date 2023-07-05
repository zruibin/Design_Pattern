/*
 * HeapSort.hpp
 *
 * Created by Ruibin.Chow on 2020/08/14.
 * Copyright (c) 2020年 Ruibin.Chow All rights reserved.
 */

#ifndef HEAPSORT_HPP
#define HEAPSORT_HPP

#include <math.h>
#include <iostream>
#include <vector>
#include "Macros.h"

/*
堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。
堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：
即子结点的键值或索引总是小于（或者大于）它的父节点。
*/

/*
1、将初始待排序关键字序列(R1,R2….Rn)构建成大顶堆，此堆为初始的无序区；
2、将堆顶元素R[1]与最后一个元素R[n]交换，此时得到新的无序区(R1,R2,……Rn-1)和新的有序区(Rn),
   且满足R[1,2…n-1]<=R[n]；
3、由于交换后新的堆顶R[1]可能违反堆的性质，因此需要对当前无序区(R1,R2,……Rn-1)调整为新堆，
   然后再次将R[1]与无序区最后一个元素交换，得到新的无序区(R1,R2….Rn-2)和新的有序区(Rn-1,Rn)。
   不断重复此过程直到有序区的元素个数为n-1，则整个排序过程完成。
*/

/*
时间复杂度(平均)：O(nlog2n)
时间复杂度(最坏)：O(nlog2n)
时间复杂度(最好)：O(nlog2n)
空间复杂度:O(1)
稳定性：不稳定
*/

NAMESPACE_START

using Vector = std::vector<int>;

void buildMaxHeap(Vector &arr);
void heapify(Vector &arr, int i, int len);
void heapSort(Vector &arr);

void testHeapSort(void)
{
    std::cout<<'\n';
    std::cout<<"---------------------------testHeapSort start--------------------------------"<<std::endl;

    Vector arr = {2,1,7,55,8,22,0,8,44,32,65,76,97,21,11,4,0,1001,100};
    std::cout << "arr size: " << arr.size() << std::endl;
    SPACE::print(arr);

    buildMaxHeap(arr);
    SPACE::print(arr);
    heapSort(arr);
    SPACE::print(arr);

    std::cout<<"---------------------------testHeapSort end--------------------------------"<<std::endl;
}


void buildMaxHeap(Vector &arr)
{   // 建立大顶堆
    int len = arr.size();
    for (int i = len/2-1; i >= 0; i--) {
        heapify(arr, i, len);
    }
}

/*堆调整*/
void heapify(Vector &arr, int i, int len)
{
    int left = 2 * i + 1;  //i的左儿子
    int right = 2 * i + 2; //i的右儿子
    int largest = i; //先设置父节点和子节点三个节点中最大值的位置为父节点下标

    if (left < len && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < len && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) { //最大值不是父节点，交换
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, largest, len); //递归调用，保证子树也是最大堆
    }
}

void heapSort(Vector &arr)
{
    int len = arr.size();
    for (int i = len-1; i >0; i--) { 
        // 将根节点(最大值)与数组待排序部分的最后一个元素交换,这样最终得到的是递增序列
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        // 待排序数组长度减一,只要对换到根节点的元素进行排序，将它下沉就好了。
        heapify(arr, 0, i);
    }
}

NAMESPACE_END

#endif /* !HEAPSORT_HPP */
