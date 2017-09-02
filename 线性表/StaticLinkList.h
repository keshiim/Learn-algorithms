//
//  StaticLinkList.h
//  算法
//
//  Created by Jason on 2017/9/1.
//  Copyright © 2017年 Jason. All rights reserved.
//

#ifndef StaticLinkList_h
#define StaticLinkList_h

#include <stdio.h>
#include <stdlib.h>
#include "ListDefine.h"
#define MAXSIZE_STATIC 1000
/*
   静态链表，每个元素E由两个元素组成，数据域：data，
   链表指针域cur(游标：用来描述下一个节点的位置)。
两个特殊元素：
   第一个是下标为0的元素，用于存放备用链表的第一个结点的下标。
   最后一个是末尾下标元素，用于存放第一个有数值的元素下标。链表为空默认是0
 */
typedef struct {
    ElemType data;
    //游标，为0是表示无指向
    int cur;
} Component, StaticLinkList[MAXSIZE_STATIC];

Status InitList_SLL(StaticLinkList space);

//分配一个空间空间，返回空闲下标，如果备用链表为空则返回0
int Malloc_SLL(StaticLinkList space);
//删除一个结点
void Free_SSL(StaticLinkList space, int i);

//静态链表的长度
int ListLength_SSL(StaticLinkList L);

//在链表中第i个元素之前插入e
Status ListInsert_SSL(StaticLinkList L, int i, ElemType e);

//在链表中删除第i位置的结点
Status ListDelete_SSL(StaticLinkList L, int i);

//打印
int ListTraverse(StaticLinkList L);

#endif /* StaticLinkList_h */
