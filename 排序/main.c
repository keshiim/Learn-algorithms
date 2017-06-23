//
//  main.c
//  排序
//
//  Created by Jason on 2017/6/23.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "StructHeader.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    SqList L = {{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, MAXSIZE};
    //int a[MAXSIZE + 1] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //SqList *L = (SqList *)malloc(sizeof(SqList));
    //L->r = a;
    //L->length = MAXSIZE;
    
    BubbleSort0(&L);
    
    return 0;
}
