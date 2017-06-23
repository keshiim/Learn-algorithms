//
//  StructHeader.h
//  算法
//
//  Created by Jason on 2017/6/23.
//  Copyright © 2017年 Jason. All rights reserved.
//

#ifndef StructHeader_h
#define StructHeader_h

//用于要排序数组个数最大值，可根据需要修改
#define MAXSIZE 10

typedef struct {
    //用于存储要排序数组，r[0]用作烧饼或临时变量
    int r[MAXSIZE + 1];
    //用于记录顺序表的长度
    int length;
} SqList;

//交换L中数组r的下标为i和j的值
void swap(SqList *L, int i, int j);

typedef enum {
    FALSE,
    TRUE
} Status;


/* 冒泡排序 */
void BubbleSort0(SqList *L); //交换
void BubbleSort(SqList *L);  //正常
void BubbleSort2(SqList *L);  //优化

#endif /* StructHeader_h */
