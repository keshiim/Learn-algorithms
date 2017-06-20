//
//  斐波那契查找.c
//  算法
//
//  Created by Jason on 2017/6/19.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "斐波那契查找.h"

int F[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

int Fibonacci_Search(int *a, int n, int key) {
    int low, high, mid, i, k = 0;
    //定义low下标的记录首位
    low = 1;
    //定义最高下标为记录的末位
    high = n;
    
    //计算n位于斐波那契数列的位置
    while (n > F[k] - 1) {
        k++;
    }
    
    //将不满的数值补全
    for (i = n; i < F[k]; i++) {
        a[i] = a[n];
    }
    
    while (low <= high) {
        //计算当前分隔的下标
        mid = low + F[k - 1] - 1;
        //若查找记录小于当前分隔记录
        if (key < a[mid]) {
            //最高下标调整到分隔下标mid -1处
            high = mid - 1;
            //斐波那契数列下标减一
            k = k - 1;
        } else if (key > a[mid]) {
            //最低下标调整到分隔下标mid+1处
            low = mid + 1;
            //斐波那契数列下标减两位
            k = k - 2;
        } else {
            if (mid <= n) {
                //若相等则说明mid即为查找到的位置
                return mid;
            } else {
                //若mid>n说明补全数值，返回n
                return n;
            }
        }
    }
    return 0;
}
