//
//  StaticLinkList.c
//  算法
//
//  Created by Jason on 2017/9/1.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "StaticLinkList.h"

Status InitList_SL(StaticLinkList space) {
    
    for (int i = 0; i < MAXSIZE_STATIC; i++) {
        space[i].cur = i + 1;
    }
    //目前静态链表为空，最后一个元素的cur为0
    space[MAXSIZE_STATIC - 1].cur = 0;
    return OK;
}
