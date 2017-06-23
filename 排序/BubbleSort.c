//
//  BubbleSort.c
//  算法
//
//  Created by Jason on 2017/6/23.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include "StructHeader.h"

//交换L中数组r的下标为i和j的值
void swap(SqList *L, int i, int j) {
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

/*
 时间复杂度分析；
   sort2最好的情况是O(n)
        最差的情况是O(n) sigma(i=2, n, i-1) = 1+2+3+...+(n-1) = n(n-1)/2
 */
//对顺序表L做交换排序（冒泡排序初级版）
void BubbleSort0(SqList *L) {
    int i, j;
    
    for (i = 1; i < L->length; i++) {
        for (j = i + 1; j <= L->length; j++) {
            if (L->r[i] > L->r[j]) {
                //交换L->r[i]与L->r[j]的值
                swap(L, i, j);
            }
        }
    }
}

//对顺序表L做冒泡排序
void BubbleSort(SqList *L) {
    int i, j;
    
    for (i = 1; i < L->length; i++) {
        //注意j是从后往前循环
        for (j = L->length - 1; j >= i; j--) {
            //若前者大于后者交换
            if (L->r[j] > L->r[j + 1]) {
                swap(L, j, j + 1);
            }
        }
    }
}

//对顺序表L作改进冒泡算法
void BubbleSort2(SqList *L) {
    int i, j;
    //flag用来作为标记
    Status flag = TRUE;
    
    //若flag为true说明有过数据交换，否则停止循环
    for (i = 1; i < L->length && flag; i++) {
        //初始为false
        flag = FALSE;
        for (j = L->length - 1; j >= i; j--) {
            if (L->r[j] > L->r[j + 1]) {
                //交换 L->r[j]与L->r[j + 1]的值
                swap(L, j, j + 1);
                //若果有数据交换，则flag为TURE
                flag = TRUE;
            }
        }
    }
}

































