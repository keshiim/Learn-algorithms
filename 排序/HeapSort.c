//
//  HeapSort.c
//  算法
//
//  Created by Jason on 2017/6/26.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include "StructHeader.h"

//已知L->r[s...m]中记录的关键字除L->r[s]之外均满足堆的定义
//本函数调整L->r[s]的关键字，使L->r[s..m]成为一个大顶堆
void HeapAdjust(SqList *L, int s, int m) {
    int temp, j;
    temp = L->r[s];
    //沿关键字较大的孩子结点向下筛选
    for (j = 2 * s; j <= m; j *= 2) {
        if (j < m && L->r[j] < L->r[j + 1]) {
            //j为关键字中较大的记录的下标
            ++j;
        }
        if (temp >= L->r[j]) {
            //rc应插入在位置s上
            break;
        }
        L->r[s] = L->r[j];
        s = j;
    }
    
    //插入
    L->r[s] = temp;
}


/* 时间复杂度：O(n*logn) */
// 对顺序表L进行堆排序
void HeapSort(SqList *L) {
    int i;
    
    //把L中的r构建一个大顶堆
    for (i = L->length / 2; i > 0; i--) {
        HeapAdjust(L, i, L->length);
    }
    
    for (i = L->length; i > 1; i--) {
        //将堆顶记录和当前未经排序子序列的最后一个记录交换
        swap(L, 1, i);
        //将L->r[1..i-1]重新调整为大顶堆
        HeapAdjust(L, 1, i - 1);
    }
}
