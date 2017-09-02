//
//  StaticLinkList.c
//  算法
//
//  Created by Jason on 2017/9/1.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "StaticLinkList.h"

Status InitList_SLL(StaticLinkList space) {
    
    for (int i = 0; i < MAXSIZE_STATIC; i++) {
        space[i].cur = i + 1;
    }
    //目前静态链表为空，最后一个元素的cur为0
    space[MAXSIZE_STATIC - 1].cur = 0;
    return OK;
}


int Malloc_SLL(StaticLinkList space) {
    //获取静态链表下一个备用链表的第一个元素下标
    int i = space[0].cur;
    //如果存在，将下一个备用链表的分量做备用
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

int ListLength_SSL(StaticLinkList L) {
    int length = 0;
    int k = L[MAXSIZE_STATIC - 1].cur;
    while (k) {
        length++;
        k = L[k].cur;
    }
    return length;
}

Status ListInsert_SSL(StaticLinkList L, int i, ElemType e) {
    int k, j, l;
    //首先将k指向头结点，即：下标为MAXSIZE_STATIC - 1的位置
    k = MAXSIZE_STATIC - 1;
    if (i < 1 || i > ListLength_SSL(L) + 1) {
        return ERROR;
    }
    j = Malloc_SLL(L);//获得空闲分量的下标
    if (j) {
        L[j].data = e;
        //找到i之前的下标位置
        for (l = 1; l <= i - 1; l++) {
            k = L[k].cur;
        }
        //插入点j
        L[j].cur = L[k].cur;
        L[k].cur = j;
    }
    return ERROR;
}
