//
//  SequenceList.h
//  算法
//
//  Created by Jason on 2017/8/29.
//  Copyright © 2017年 Jason. All rights reserved.
//

#ifndef SequenceList_h
#define SequenceList_h

#include <stdio.h>

// 存储看空间初始分配量 (顺序链表)
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef int ElemType;
typedef struct {
    //数组存储元素，最大值MAXSIZE
    ElemType data[MAXSIZE];
    int length;
} SqList;

/* ----Operation:----- */
// Status是函数的类型，其值是函数结果状态代码，如OK等
// 初始条件：循序线性表L已经存在，1<=i<=ListLength(L)
// 操作结果：用e返回L中第i个数据元素的值
Status GetElem(SqList L, int i, ElemType *e);

#endif /* SequenceList_h */
