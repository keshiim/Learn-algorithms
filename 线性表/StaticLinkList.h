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
 
 */
typedef struct {
    ElemType data;
    //游标，为0是表示无指向
    int cur;
} Component, StaticLinkList[MAXSIZE_STATIC];

Status InitList_SL(StaticLinkList space);

#endif /* StaticLinkList_h */
