//
//  LinkList.c
//  算法
//
//  Created by Jason on 2017/8/30.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "LinkList.h"
//时间复杂度O(1)
Status InitNode_LL(LinkList *node) {
    *node = (LinkList)malloc(sizeof(Node));
    return OK;
}
//时间复杂度O(n)
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

//时间复杂度O(n)
Status ListInsert_LL(LinkList *L, int i, ElemType e) {
    int k = 1;
    LinkList p = *L, s;
    //寻找第i-1个结点
    while (p && k < i) {
        p = p->next;
        k++;
    }
    //第i个结点不存在
    if (!p || k > i) {
        return ERROR;
    }
    //初始化
    InitNode_LL(&s);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//时间复杂度O(n)
Status ListDelete_LL(LinkList *L, int i, ElemType *e) {
    int k = 1;
    LinkList p = *L, cur;
    //寻找第i-1个结点
    while (p && k < i) {
        p = p->next;
        k++;
    }
    if (!(p->next) || k > i) {
        return ERROR;
    }
    cur = p->next;
    p->next = cur->next;
    *e = cur->data;
    //让系统回收结点cur
    free(cur);
    return OK;
}

//头插法
void CreateListHead(LinkList *L, int n) {
    LinkList p;
    int i = 0;
    //初始化L
    InitNode_LL(L);
    (*L)->next = NULL;
    while (i < n) {
        //初始化p
        InitNode_LL(&p);
        p->data = arc4random() % 100 + 1;
        p->next = (*L)->next;
        //头插法
        (*L)->next = p;
        
        i++;
    }
}

void CreateListTail(LinkList *L, int n) {
    LinkList p, r;
    int i = 0;
    //初始化L
    InitNode_LL(L);
    (*L)->next = NULL;
    //r为指向尾部的结点
    r = *L;
    while (i < n) {
        //初始化p
        InitNode_LL(&p);
        p->data = arc4random() % 100 + 1;
        // 将表尾终端结点的指针指向新结点
        r->next = p;
        // 将当前新结点定义为表尾结点
        r = p;
        i++;
    }
    //标记表尾结点结束
    r->next = NULL;
}

//时间复杂度O(n)
Status ClearList_LL(LinkList *L) {
    LinkList p, q;
    p = (*L)->next;
    while (p) {
        q = p->next;
        p->next = NULL;
        free(p);
        p = q;
    }
    //头结点指针域置空
    (*L)->next = NULL;
    return OK;
}







