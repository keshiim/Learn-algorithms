//
//  SqDoubleStack.c
//  栈和队列
//
//  Created by Jason on 2017/9/15.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "SqDoubleStack.h"

Status Push(SqDoubleStack *S, SElemType e, int stackNumber) {
    if (S->top1 + 1 == S->top2) {
        return ERROR;
    }
    if (stackNumber == 1) {
        S->data[++S->top1] = e;
    } else if (stackNumber == 2) {
        S->data[--S->top2] = e;
    }
    return OK;
}

Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber) {
    if (stackNumber == 1) {
        if (S->top1 == -1) {
            return ERROR;
        }
        *e = S->data[S->top1--];
    } else if (stackNumber == 2) {
        if (S->top2 == MAXSIZE) {
            return ERROR;
        }
        *e = S->data[S->top2++];
    }
    return OK;
}
