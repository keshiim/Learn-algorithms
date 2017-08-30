//
//  SequenceList.c
//  算法
//
//  Created by Jason on 2017/8/29.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "SequenceList.h"

Status GetElem(SqList L, int i, ElemType *e) {
    if (L.length == 0 || i < 1 || i > L.length) {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e) {
    int k;
    //循序表已满
    if (L->length == MAXSIZE) {
        return ERROR;
    }
    //当i不在范围内时
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    //如果插入数据不在表尾
    if (i <= L->length) {
        for (k = L->length - 1; k >= i - 1; k--) {
            L->data[k + 1] = L->data[k];
        }
    }
    
    //将新元素插入
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    int k;
    // 如果表位空
    if (L->length == 0) {
        return ERROR;
    }
    // 当i不在范围内时
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    
    *e = L->data[i - 1];
    //如果删除输入不在表尾
    if (i < L->length) {
        for (k = i; k < L->length; k++) {
            L->data[k - 1] = L->data[k];
        }
    }
    //长度减一
    L->length--;
    return OK;
}


















