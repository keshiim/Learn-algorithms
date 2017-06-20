//
//  main.m
//  算法
//
//  Created by Jason on 2017/5/10.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int rc = puts("Hello World");
    
    if (rc == EOF)
        perror("puts()"); // POSIX requires that errno is set
    return 0;
}
