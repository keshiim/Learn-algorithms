//
//  main.c
//  栈和队列
//
//  Created by Jason on 2017/9/15.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include "StackHeapHeader.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /*
    //////////// sequence stack test code /////////////
    int j;
    SqStack s;
    int e;
    if(InitStack(&s)==OK)
        for(j=1;j<=10;j++)
            Push(&s,j);
    printf("栈中元素依次为：");
    StackTraverse(s);
    Pop(&s,&e);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    GetTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
    ////////////////////////////////////////////////////
     */
    
    int j;
    SqDoubleStack s;
    int e;
    if(D_InitStack(&s)==OK)
    {
        for(j=1;j<=5;j++)
            D_Push(&s,j,1);
        for(j=MAXSIZE;j>=MAXSIZE-2;j--)
            D_Push(&s,j,2);
    }
    
    printf("栈中元素依次为：");
    D_StackTraverse(s);
    
    printf("当前栈中元素有：%d \n", D_StackLength(s));
    
    D_Pop(&s,&e,2);
    printf("弹出的栈顶元素 e=%d\n",e);
    printf("栈空否：%d(1:空 0:否)\n", D_StackEmpty(s));
    
    for(j=6;j<=MAXSIZE-2;j++)
        D_Push(&s,j,1);
    
    printf("栈中元素依次为：");
    D_StackTraverse(s);
    
    printf("栈满否：%d(1:否 0:满)\n",D_Push(&s,100,1));
    
    
    D_ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n",D_StackEmpty(s));
    return 0;
}
