//
//  散列表查找.c
//  算法
//
//  Created by Jason on 2017/6/22.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "散列表查找.h"
#include <stdlib.h>

typedef int Status;
#define SUCCESS 1
#define UNSUCCESS 0

//定义散列表长为数组的长度
#define HASHSIZE 12
#define NULLKEY -32768

typedef struct {
    //数据元素存储基址，动态分配数组
    int *elem;
    //当前数据元素个数
    int count;
} HashTable;

//算列表表长，全局变量
int m = 0;

/*
 初始化散列表 
 */
Status InitHashTable(HashTable *H) {
    int i;
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int));
    
    for (i = 0; i < m; i++) {
        H->elem[i] = NULLKEY;
    }
    return SUCCESS;
}


/*
 散列函数
 */
int Hash(int key) {
    //除留余数法
    return key % m;
}


/*
 插入关键字进散列表
 */
void InsertHash(HashTable *H, int key) {
    //求散列地址
    int addr = Hash(key);
    
    //如果不为空，则冲突
    while (H->elem[addr] != NULLKEY) {
        //开放定址法的线性探测
        addr = (addr + 1) % m;
    }
    H->elem[addr] = key;
}


/*
 散列表查找关键字
 */
Status SearchHash(HashTable H, int key, int *addr) {
    //求散列地址
    *addr = Hash(key);
    
    //如果不相等，则冲突
    while (H.elem[*addr] != key) {
        //开放定址法的线性探测
        *addr = (*addr + 1) % m;
        if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) {
            //如果循环回到原点，则说明关键字不存在
            return UNSUCCESS;
        }
    }
    
    return SUCCESS;
}

































