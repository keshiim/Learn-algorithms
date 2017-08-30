//
//  LinkList.h
//  算法
//
//  Created by Jason on 2017/8/30.
//  Copyright © 2017年 Jason. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>
#include "ListDefine.h"

typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList; //定义LinkList

Status InitNode_LL(LinkList *node);

// 初始条件：链表L已存在，1<=i<=ListLength(L)
// 操作结果：用e返回L中第i个数据元素的值
Status GetElem_LL(LinkList L, int i, ElemType *e);

Status ListInsert_LL(LinkList *L, int i, ElemType e);

#endif /* LinkList_h */
