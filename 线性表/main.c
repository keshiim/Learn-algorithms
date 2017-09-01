//
//  main.c
//  线性表
//
//  Created by Jason on 2017/8/29.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include "ListHeader.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    SqList *L = NULL;
    InitList(&L);
    for (int i = 0; i < 10; i++) {
        L->data[i] = arc4random() % 30;
        L->length = i + 1;
    }
    
    ListInsert(L, 8, 999);
    int elem;
    ListDelete(L, 8, &elem);
    printf("%d\n", elem);
    
    LinkList p;
    
    CreateListHead(&p, 10);
    CreateListTail(&p, 10);
    for (int i = 1; i <= 10; i++) {
        ElemType e;
        GetElem_LL(p, i, &e);
        printf("%d\n", e);
    }
    ClearList_LL(&p);
    return 0;
}
