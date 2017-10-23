//
//  SqDoubleStack.c
//  栈和队列
//
//  Created by Jason on 2017/9/15.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "SqDoubleStack.h"

Status D_visit(SElemType c) {
    printf("%d ", c);
    return OK;
}

Status D_InitStack(SqDoubleStack *S) {
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

Status D_ClearStack(SqDoubleStack *S) {
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

Status D_StackEmpty(SqDoubleStack S) {
    if (S.top1 == -1 && S.top2 == MAXSIZE) {
        return TRUE;
    }
    return FALSE;
}

int D_StackLength(SqDoubleStack S) {
    return (S.top1 + 1) + (MAXSIZE - S.top2);
}

Status D_StackTraverse(SqDoubleStack S) {
    int i = 0;
    for (; i <= S.top1; i++) {
        D_visit(S.data[i]);
    }
    i = S.top2;
    for (; i < MAXSIZE; i++) {
        D_visit(S.data[i]);
    }
    return OK;
}

Status D_Push(SqDoubleStack *S, SElemType e, int stackNumber) {
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

Status D_Pop(SqDoubleStack *S, SElemType *e, int stackNumber) {
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
