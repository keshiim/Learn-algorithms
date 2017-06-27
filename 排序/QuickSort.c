//
//  QuickSort.c
//  算法
//
//  Created by Jason on 2017/6/27.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include "StructHeader.h"

void InsertSort(SqList *L);

/* 交换顺序表L中子表的记录，是枢轴记录到位，并返回其所在的位置 
   此时在它之前（后）的记录均不大（小）于它。*/
int Partition(SqList *L, int low, int high) {
    int pivotkey;
    //用子表的第一个记录作枢轴记录
    pivotkey = L->r[low];
    //从表的两端交替向中间扫描
    while (low < high) {
        while (low < high && L->r[high] >= pivotkey) {
            high--;
        }
        //将比枢轴记录小的记录交换到低端
        swap(L, low, high);
        
        while (low < high && L->r[low] <= pivotkey) {
            low++;
        }
        //将比枢轴记录大的记录交换到高端
        swap(L, low, high);
    }
    
    //返回枢轴所在的位置
    return low;
}

/* 优化：交换顺序表L中子表的记录，是枢轴记录到位，并返回其所在的位置
 此时在它之前（后）的记录均不大（小）于它。*/
int Partition1(SqList *L, int low, int high) {
    int pivotkey;
    
    int m = low + (high - low) / 2;
    if (L->r[low] > L->r[high]) {
        //交换左端与右端数据，保证左端较小
        swap(L, low, high);
    }
    if (L->r[m] > L->r[high]) {
        //交换中间与右端数据，保证中间较小
        swap(L, m, high);
    }
    if (L->r[m] > L->r[low]) {
        //交换中间与左端数据，保证中间较小
        swap(L, m, low);
    }
    
    //用子表的第一个记录作枢轴记录
    pivotkey = L->r[low];
    //从表的两端交替向中间扫描
    while (low < high) {
        while (low < high && L->r[high] >= pivotkey) {
            high--;
        }
        //将比枢轴记录小的记录交换到低端
        swap(L, low, high);
        
        while (low < high && L->r[low] <= pivotkey) {
            low++;
        }
        //将比枢轴记录大的记录交换到高端
        swap(L, low, high);
    }
    
    //返回枢轴所在的位置
    return low;
}
/* 1的基础上优化：交换顺序表L中子表的记录，是枢轴记录到位，并返回其所在的位置
此时在它之前（后）的记录均不大（小）于它。*/
int Partition2(SqList *L, int low, int high) {
    int pivotkey;
    
    int m = low + (high - low) / 2;
    if (L->r[low] > L->r[high]) {
        //交换左端与右端数据，保证左端较小
        swap(L, low, high);
    }
    if (L->r[m] > L->r[high]) {
        //交换中间与右端数据，保证中间较小
        swap(L, m, high);
    }
    if (L->r[m] > L->r[low]) {
        //交换中间与左端数据，保证中间较小
        swap(L, m, low);
    }
    
    //用于子表的第一个记录作枢轴记录
    pivotkey = L->r[low];
    //将枢轴关键字备份到L->r[0]
    L->r[0] = pivotkey;
    //从表的两端交替向中间扫描
    while (low < high) {
        while (low < high && L->r[high] >= pivotkey) {
            high--;
        }
        //采用替换而不是交换的方式进行操作
        L->r[low] = L->r[high];
        
        while (low < high && L->r[low] <= pivotkey) {
            low++;
        }
        //采用替换而不是交换的方式操作
        L->r[high] = L->r[low];
    }
    //将枢轴的值替换会L->r[low]
    L->r[low] = L->r[0];
    //返回枢轴所在的位置
    return low;
}

/* 对顺序表L中的子序列L->r[low..high]作快速排序 */
void QSort(SqList *L, int low, int high) {
    int pivot;
    if (low < high) {
        //将L->r[low..high]一分为二
        //算出枢轴值pivot
        pivot = Partition(L, low, high);
        //对低子表递归排序
        QSort(L, low, pivot - 1);
        //对高子表递归排序
        QSort(L, pivot + 1, high);
    }
}

#define MAX_LENGTH_INSERT_SORT 7 //数组长度阈值
/* 优化算法：对顺序表L中的子序列L.r[low..high]作快速排序 */
void QSort1(SqList *L, int low, int high) {
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT) {
        //当high - low大于常数时用快速排序
        //将L.r[low..high]一分为二，并算出枢轴值pivot
        pivot = Partition(L, low, high);
        //对低子表递归排序
        QSort1(L, low, pivot - 1);
        //对高子表递归排序
        QSort1(L, pivot + 1, high);
    } else {
        //当high-low小于等于常数时用直接插入排序
        InsertSort(L);
    }
}

/* 优化快排：采用迭代代替递归方法可以缩减对战深度，提高整体性能
 对顺序表L中的子序列L.r[low..high]作快速排序 */
void QSort2(SqList *L, int low, int high) {
    int pivot;
    if ((high - low) > MAX_LENGTH_INSERT_SORT) {
        while (low < high) {
            //L.r[low..high]一分为二，算出枢轴值
            pivot = Partition2(L, low, high);
            //对低子表递归排序
            QSort2(L, low, pivot - 1);
            //尾递归
            low = pivot + 1;
        }
    } else {
        InsertSort(L);
    }
}

/* 时间复杂度：O(nlogn)
   空间复杂度：O(logn) */
/* 对顺序表L作快速排序 */
void QuickSort(SqList *L) {
    QSort(L, 1, L->length);
}
