//
//  MergingSort.c
//  算法
//
//  Created by Jason on 2017/6/26.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "StructHeader.h"

/* 将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n] */
void Merge(int SR[], int TR[], int i, int m, int n) {
    int j, k, l;
    //将SR中记录由小到大归并入TR
    for (j = m + 1, k = i; i <= m && j <= n; k++) {
        if (SR[i] < SR[j]) {
            TR[k] = SR[i++];
        } else {
            TR[k] = SR[j++];
        }
    }
    if (i <= m) {
        for (l = 0; l <= m - i; l++) {
            //将剩余的SR[i..m]赋值到TR
            TR[k + 1] = SR[i + 1];
        }
    }
    
    if (j <= n) {
        for (l = 0; l <= n - j; l++) {
            //将剩余的SR[j..n]赋值到TR
            TR[k + 1] = SR[j + 1];
        }
    }
}

/* 将SR[s..t]归并排序为TR1[s..t] */
void MSort(int SR[], int TR1[], int s, int t) {
    int m;
    int TR2[MAXSIZE + 1];
    
    if (s == t) {
        TR1[s] = SR[s];
    }
    else {
        //将SR[s..t]平分为SR[s..m]和SR[m+1..t]
        m = (s + t) / 2;
        //递归将SR[s..m]归并为有序的TR2[s..m]
        MSort(SR, TR2, s, m);
        //递并将SR[m+1..t]归并为有序TR2[m+1..t]
        MSort(SR, TR2, m + 1, t);
        //将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t]
        Merge(TR2, TR1, s, m, t);
    }
}

/* 算法的时间复杂度：O(nlogn)
        空间复杂度：O(n+logn)
 */
//对顺序表L作归并排序
void MergeSort(SqList *L) {
    MSort(L->r, L->r, 1, L->length);
}



#pragma mark - 归并排序优化，非递归方式
//将SR[]中相邻长度为s的子序列两两归并到TR[]
void MergePass(int SR[], int TR[], int s, int n) {
    int i = 1;
    int j;
    while (i <= n - 2 * s + 1) {
        //两两归并
        Merge(SR, TR, i, i + s - 1, i + 2 * s -1);
        i = i + 2 * s;
    }
    //归并最后两个序列
    if (i < n - s + 1) {
        Merge(SR, TR, i, i + s - 1, n);
    } else {
        for (j = i; j <= n; j++) {
            TR[j] = SR[j];
        }
    }
}


/* 算法的时间复杂度：O(nlogn)
   空间复杂度：O(n)
   对顺序表L作归并非递归排序
 */
void MergeSort2(SqList *L) {
    //申请额外空间
    int *TR = (int *)malloc(L->length * sizeof(int));
    int k = 1;
    while (k < L->length) {
        MergePass(L->r, TR, k, L->length);
        //子序列长度加倍
        k = 2 * k;
        MergePass(TR, L->r, k, L->length);
        //子序列长度加倍
        k = 2 * k;
    }
}























