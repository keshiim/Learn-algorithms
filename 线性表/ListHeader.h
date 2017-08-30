//
//  ListHeader.h
//  算法
//
//  Created by Jason on 2017/8/29.
//  Copyright © 2017年 Jason. All rights reserved.
//

#ifndef ListHeader_h
#define ListHeader_h

/*
 ADT List
 Data
    线性表的数据对象几何为{a1, a2, a3, a4, a5, ...., an},每个元素的类型均为DataType。
    其中，除第一个元素a1外，每一个元素有且只有一个直接前驱元素，除了最后一个元素an外，每一个元素有且只有一个直接后继元素。
    元素直接的关系是一对一的关系。
 Operation
    InitList(*L): 初始化操作,建立一个空的线性表L。
    ListEmpty(L): 若线性表为空，返回true，否则返回false。
    ClearList(*L): 将线性表清空。
    GetElem(L, i, *e) 在线性表L中查的第i个位置元素返回给e。
    LocateElem(L, e） 在线性表L中查找与给定值e相等的元素，如果查找成功，返回改元素在表中序号表示成功。
 */
#include "SequenceList.h"

#endif /* ListHeader_h */
