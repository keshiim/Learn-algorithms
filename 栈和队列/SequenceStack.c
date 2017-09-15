//
//  SequenceStack.c
//  栈和队列
//
//  Created by Jason on 2017/9/15.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "SequenceStack.h"

Status visit(SElemType c) {
    printf("%d ", c);
    return OK;
}

Status InitStack(SqStack *S) {
    S->top = -1;
    return OK;
}

Status clearStack(SqStack *S) {
    S->top = -1;
    return OK;
}

Status StackEmpty(SqStack S) {
    if (S->top == -1) {
        return TRUE;
    }
    return FALSE;
}

int StackLength(SqStack S) {
    return S->top + 1;
}

Status GetTop(SqStack S, SElemType *e) {
    if (S->top == -1) {
        return ERROR;
    }
    *e = S->data[S->top];
    return OK;
}

Status StackTraverse(SqStack S) {
    for (int i = 0; i <= S->top; i++) {
        visit(S->data[i]);
    }
    printf("\n");
    return OK;
}

Status Push(SqStack *S, SElemType e) {
    if (S->top == MAXSIZE - 1) {
        return ERROR;
    }
    
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status Pop(SqStack *S, SElemType *e) {
    if (S->top == -1) {
        return ERROR;
    }
    *e = S->data[S->top];
    S->top--;
    return OK;
}
