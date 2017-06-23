//
//  SelectSort.c
//  算法
//
//  Created by Jason on 2017/6/23.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include "StructHeader.h"


/*
 时间复杂度分析：O(n^2) sigma(i=2, n, i-1) = 1+2+3+...+(n-1) = n(n-1)/2
 最好的情况交换次数为0
 最坏的情况交换次数为n-1
 
 效率高于 冒泡排序
 */
// 对顺序表L作简单选择排序
void SelectSort(SqList *L) {
    int i, j, min;
    
    for (i = 1; i < L->length; i++) {
        //将当前下标定义为最小值下标
        min = i;
        //循环之后的数据
        for (j = i + 1; j <= L->length; j++) {
            //如果小于当前最小值的关键字
            if (L->r[min] > L->r[j]) {
                //将此关键字的下标赋值给min
                min = j;
            }
        }
        //若min不等于i，说明找到最小值，交换
        if (i != min) {
            //交换L->r[i]于L->r[min]的值
            swap(L, i, min);
        }
    }
}
