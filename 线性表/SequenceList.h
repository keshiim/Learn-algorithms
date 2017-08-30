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
#include "ListDefine.h"

typedef struct {
    //数组存储元素，最大值MAXSIZE
    ElemType data[MAXSIZE];
    int length;
} SqList;

/* ----Operation:----- */
Status InitList(SqList **L);
Status ListEmpty(SqList L);
Status ClearList(SqList *L);
Status LocateElem(SqList L, int *i, ElemType e);
// Status是函数的类型，其值是函数结果状态代码，如OK等
// 初始条件：循序线性表L已经存在，1<=i<=ListLength(L)
// 操作结果：用e返回L中第i个数据元素的值
Status GetElem(SqList L, int i, ElemType *e);

Status SetElem(SqList L, int i, ElemType e);

// 初始条件：顺序线性表L已存在，1<=i<=ListLength(L)
// 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1
Status ListInsert(SqList *L, int i, ElemType e);

// 初始条件：顺序线性表L已存在，1<=i<=Listlength(L)
// 操作结果：删除L的第i个位置的元素，并用e返回，L的长度减一
Status ListDelete(SqList *L, int i, ElemType *e);

#endif /* SequenceList_h */















