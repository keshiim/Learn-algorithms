//
//  main.c
//  查找
//
//  Created by Jason on 2017/6/19.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include "折半查找.c"
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[10] = {0, 2, 5, 8, 11, 16, 38, 64, 231, 2223};
    int n = 9;
    int index = Binary_Search(a, n, 231);
    printf("got: %d\n", index);
    return 0;
}
