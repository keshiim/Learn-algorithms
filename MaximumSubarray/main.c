//
//  main.c
//  MaximumSubarray
//
//  Created by Jason on 2017/5/10.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>

int maxSubArray(int* nums, int numsSize) {
    int maxCurrent = nums[0];
    int maxGlobal  = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        maxCurrent = (maxCurrent + nums[i]) > nums[i] ? (maxCurrent + nums[i]) : nums[i];
        maxGlobal = (maxCurrent > maxGlobal) ? maxCurrent : maxGlobal;
    }
    return maxGlobal;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {-2, 1, -3, 4, 6, 2, -1};
    printf("%d\n", maxSubArray(a, 7));
    return 0;
}
