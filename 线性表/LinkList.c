//
//  LinkList.c
//  算法
//
//  Created by Jason on 2017/8/30.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "LinkList.h"

Status InitNode_LL(LinkList *node) {
    *node = (LinkList)malloc(sizeof(Node));
    return OK;
}

Status GetElem_LL(LinkList L, int i, ElemType *e) {
    LinkList p = L->next;
    int k = 1;
    while (p && k < i) {
        p = p->next;
        k++;
    }
    if (!p || k > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}


Status ListInsert_LL(LinkList *L, int i, ElemType e) {
    int j = 1;
    LinkList p = *L, s;
    //寻找第i-1个结点
    while (p && j < i) {
        p = p->next;
        j++;
    }
    //第i个结点不存在
    if (!p && j > i) {
        return ERROR;
    }
    //初始化
    InitNode_LL(&s);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}


