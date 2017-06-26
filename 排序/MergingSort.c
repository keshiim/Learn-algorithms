//
//  MergingSort.c
//  算法
//
//  Created by Jason on 2017/6/26.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
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
