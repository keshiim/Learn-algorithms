//
//  插值查找.c
//  算法
//
//  Created by Jason on 2017/6/19.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "插值查找.h"
//插值查找算法，二分查找优化扩展
int Binary_Search_insert(int *a, int n, int key) {
    int low; int high; int mid;
    //定义最低下标为记录首位
    low = 1;
    //定义最高下标为记录末尾
    high = n;
    
    while (low <= high) {
        //折半
        //mid = (low + high) / 2
        //    = low + (high - low) / 2
        //    = low + (key - a[low])/(a[high] - a[low]) * (high - low)
        // 此变换提高了二分查找的效率 O(logn)
        mid = low + (key - a[low]) / (a[high] - a[low]) * (high - low);
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
