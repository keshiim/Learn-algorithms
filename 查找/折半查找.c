//
//  折半查找.c
//  算法
//
//  Created by Jason on 2017/6/19.
//  Copyright © 2017年 Jason. All rights reserved.
//


/**
 折半查找和插值查找都属于对于有序序列进行查找的方式
 a[3] = {1, 2, 3}
 */
#include "折半查找.h"

int Binary_Search(int *a, int n, int key) {
    int low, high, mid;
    //定义最低下标为记录首位
    low = 1;
    //定义最高下标为记录末尾
    high = n;
    
    while (low <= high) {
        //折半
        mid = (low + high) / 2;
        //若查找值比中值小
        if (key < a[mid]) {
            //最高下标调整到中位下标小一位
            high = mid - 1;
        } else if (key > a[mid]) {
            //最低下标调整到中位小标大一位
            low = mid + 1;
        } else {
            return mid;
        }
    }
    
    return 0;
}
