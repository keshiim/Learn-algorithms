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

/*
   Malloc 和 Free 主要是修改备用链表
 */
int Malloc_SLL(StaticLinkList space) {
    //获取静态链表下一个备用链表的第一个元素下标
    int i = space[0].cur;
    //如果存在，将下一个备用链表的分量做备用
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

void Free_SSL(StaticLinkList space, int i) {
    //把备用链表cur赋给要删除的元素
    space[i].cur = space[0].cur;
    //把要删除元素的小标还给备用链表，并作为备用链表的第一位置
    space[0].cur = i;
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

Status ListDelete_SSL(StaticLinkList L, int i) {
    int k, j;
    //首先将k指向头结点，即：下标为MAXSIZE_STATIC - 1的位置
    k = MAXSIZE_STATIC - 1; //999
    if (i < 1 || i > ListLength_SSL(L)) {
        return ERROR;
    }
    
    //找到i之前的下标位置
    for (j = 1; j <= i - 1; j++) {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}

int ListTraverse(StaticLinkList L) {
    int i = L[MAXSIZE_STATIC - 1].cur;
    while (i) {
        printf("%c ", L[i].data);
        i = L[i].cur;
    }
    printf("\n");
    return ListLength_SSL(L);
}


Status __InitList_SLL(StaticLinkList space) {
    for (int i = 0; i < MAXSIZE_STATIC - 1; i++) {
        space[i].cur = i + 1;
    }
    space[MAXSIZE_STATIC - 1].cur = 0;
    return OK;
}
//分配一个空间空间，返回空闲下标，如果备用链表为空则返回0
int __Malloc_SLL(StaticLinkList space) {
    int i = space[0].cur;
    if (space[0].cur) {
        space[0].cur = space[i].cur;
    }
    return i;
}

//删除一个结点
void __Free_SSL(StaticLinkList space, int i) {
    space[i].cur = space[0].cur;
    space[0].cur = i;
}

//静态链表的长度
int __ListLength_SSL(StaticLinkList L) {
    int j = 0;
    int i = L[MAXSIZE_STATIC].cur;
    while (i) {
        j++;
        i = L[i].cur;
    }
    return j;
}

//在链表中第i个元素之前插入e
Status __ListInsert_SSL(StaticLinkList L, int i, ElemType e) {
    if (i < 0 || i > __ListLength_SSL(L) + 1) {
        return ERROR;
    }
    int j = __Malloc_SLL(L); // 获取下一个要插入空分量下标
    int k = MAXSIZE_STATIC - 1;
    if (j) {
        L[j].data = e;
        for (int l = 1; l <= i - 1; l++) { //查找第i-1个元素的下标
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}

//在链表中删除第i位置的结点
Status __ListDelete_SSL(StaticLinkList L, int i) {
    if (i < 0 || i > __ListLength_SSL(L)) {
        return ERROR;
    }
    int k = MAXSIZE_STATIC - 1, j; //初始头结点的位置
    for (j = 1; j <= i - 1; j++) {//循环查找第i-1个元素的下标
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    __Free_SSL(L, j);
    return OK;
}

//打印
int __ListTraverse(StaticLinkList L) {
    int i = L[MAXSIZE_STATIC - 1].cur;
    while (i) {
        printf("%d ", L[i].data);
        i = L[i].cur;
    }
    printf("\n");
    return __ListLength_SSL(L);
}




