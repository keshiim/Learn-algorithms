//
//  SqDoubleStack.h
//  栈和队列
//
//  Created by Jason on 2017/9/15.
//  Copyright © 2017年 Jason. All rights reserved.
//

#ifndef SqDoubleStack_h
#define SqDoubleStack_h

#include <stdio.h>
#include "ADTDefine.h"

typedef struct {
    SElemType data[MAXSIZE];
    int top1; //栈1栈顶指针
    int top2; //栈2栈顶指针
} SqDoubleStack;

Status D_visit(SElemType c);
Status D_InitStack(SqDoubleStack *S);
Status D_ClearStack(SqDoubleStack *S);
Status D_StackEmpty(SqDoubleStack S);
int D_StackLength(SqDoubleStack S);
Status D_StackTraverse(SqDoubleStack S);

//插入元素e为新的栈顶元素
Status D_Push(SqDoubleStack *S, SElemType e, int stackNumber);

Status D_Pop(SqDoubleStack *S, SElemType *e, int stackNumber);

#endif /* DoubleStack_h */
