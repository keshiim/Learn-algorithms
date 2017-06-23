//
//  InsertSort.c
//  算法
//
//  Created by Jason on 2017/6/23.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include "StructHeader.h"

/*
 时间复杂度分析：O(n^2) 
    比较次数sigma(i=2, n, i) = 1+2+3+...+(n-1) = (n + 2)(n-1)/2
    移动次数sigma(i=2, n, i+1) = (n + 4)(n-1)/2
 平均比较和移动次数约为：n^2/4
 */
//对顺序表L作直接插入排序
void InsertSort(SqList *L) {
    int i, j;
    for (i = 2; i <= L->length; i++) {
        //需将L->r[i] 插入有序子列表
        if (L->r[i] < L->r[i - 1]) {
            //设置哨兵
            L->r[0] = L->r[i];
            
            for (j = i - 1; L->r[j] > L->r[0]; j--) {
                //记录后移
                L->r[j + 1] = L->r[j];
            }
            //插入到正确位置
            L->r[j + 1] = L->r[0];
        }
    }
}
