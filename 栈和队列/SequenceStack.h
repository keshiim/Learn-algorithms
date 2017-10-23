//
//  SequenceStack.h
//  栈和队列
//
//  Created by Jason on 2017/9/15.
//  Copyright © 2017年 Jason. All rights reserved.
//

#ifndef SequenceStack_h
#define SequenceStack_h

#include <stdio.h>
#include "ADTDefine.h"

typedef struct {
    SElemType data[MAXSIZE];
    int top; // 用于栈顶指针
} SqStack;

Status visit(SElemType c);
Status InitStack(SqStack *S);
Status ClearStack(SqStack *S);
Status StackEmpty(SqStack S);
int StackLength(SqStack S);
Status GetTop(SqStack S, SElemType *e);
Status StackTraverse(SqStack S);

//插入元素e为新的栈顶元素
Status Push(SqStack *S, SElemType e);

Status Pop(SqStack *S, SElemType *e);
#endif /* SequenceStack_h */
