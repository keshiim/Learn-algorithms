//
//  ShellSort.c
//  算法
//
//  Created by Jason on 2017/6/23.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include "StructHeader.h"

/* 时间复杂度分析：O(n^3/2) */
//对顺序表L作希尔排序
void ShellSort(SqList *L) {
    int i, j;
    int increment = L->length;
    
    do {
        //增量序列
        increment = increment / 3 + 1;
        for (i = increment + 1; i <= L->length; i++) {
            if (L->r[i] < L->r[i - increment]) {
                //需将L->r[i]插入有序增量字表
                //暂存在L->r[0]
                L->r[0] = L->r[i];
                for (j = i - increment; j > 0 && L->r[0] < L->r[j]; j -= increment) {
                    //记录后移，查找插入位置
                    L->r[j + increment] = L->r[j];
                }
                //插入
                L->r[j + increment] = L->r[0];
            }
        }
    } while (increment > 1);
}



