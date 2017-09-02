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
    /*******顺序链表*****/
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
    /*******顺序链表*****/
    
    /*******链式链表*****/
    LinkList p;
    CreateListHead(&p, 10);
    CreateListTail(&p, 10);
    for (int i = 1; i <= 10; i++) {
        ElemType e;
        GetElem_LL(p, i, &e);
        printf("%d\n", e);
    }
    ClearList_LL(&p);
    /*******链式链表*****/
    
    /*******静态链表*****/
    int length = 0;
    StaticLinkList space;
    InitList_SLL(space);
    
    ListInsert_SSL(space, 1, 'A');
    ListInsert_SSL(space, 2, 'A'+1);
    ListInsert_SSL(space, 3, 'A'+2);
    ListInsert_SSL(space, 4, 'A'+3);
    ListInsert_SSL(space, 5, 'A'+4);
    
    length = ListTraverse(space);
    printf("长=%d\n", length);
    ListDelete_SSL(space, 2);
    
    length = ListTraverse(space);
    printf("长=%d\n", length);
    /*******静态链表*****/
    return 0;
}
