//
//  二叉排序树查找.c
//  算法
//
//  Created by Jason on 2017/6/19.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "二叉排序树查找.h"

//二叉树的二叉列表结点结构定义
typedef struct BiTNode {
    //结点数据
    int data;
    //左右孩子结点
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef enum Status {
    FALSE,
    TRUE,
} Status;

/*
  递归查找二叉排序树T中是否存在key，
  指针 f 指向 T 的双亲，其初始调用值为NULL
  若查找成功，则指针p指向改数据元素结点，并返回TRUE，
  否则指针p指向查找路径上访问的最后一个结点，并返回FALSE
 */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) {
    //查找不成功
    if (!T) {
        *p = f;
        return FALSE;
    }
    //查找成功
    else if (key == T->data) {
        *p = T;
        return TRUE;
    }
    else if (key < T->data) {
        //在左子树继续查找
        return SearchBST(T->lchild, key, T, p);
    }
    else {
        //在右子树继续查找
        return SearchBST(T->rchild, key, T, p);
    }
}

/* 二叉排序树 - 插入操作 
   当二叉排序树T中不存在关键字等于key的数据源时，
   插入key并返回TRUE，否则返回FALSE
 */
Status InsertBST(BiTree *T, int key) {
    BiTree p, s;
    //查找不成功
    if (SearchBST(*T, key, NULL, &p)) {
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (p == NULL) {
            //插入s为新的根结点
            *T = s;
        }
        else if (key < p->data) {
            //插入s为左孩子
            p->lchild = s;
        }
        else {
            //插入s为右孩子
            p->rchild = s;
        }
        return TRUE;
    } else {
        //树中已有关键字相同的结点，不再插入
        return FALSE;
    }
}

void testDemo() {
    int i;
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    BiTree T = NULL;
    for (i = 0; i < 10; i++) {
        InsertBST(&T, a[i]);
    }
    
}

//从二叉排序树中删除结点P，并重接它的左或右子树
Status Delete(BiTree *p) {
    BiTree q, s;
    //右子树空, 则需要重接它的左子树
    if ((*p)->rchild == NULL) {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    // 只需重接它的右子树
    else if ((*p)->lchild == NULL) {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    //左右子树均不空
    else {
        q = *p; s = (*p)->lchild;
        //转左，然后享有到尽头 （找待删结点的前驱）
        while (s->rchild) {
            q = s; s = s->rchild;
        }
        
        //s指向被删除结点的直接前驱
        (*p)->data = s->data;
        if (q != *p) {
            //重接q的右子树
            q->rchild = s->lchild;
        } else {
            //重接q的左子树
            q->lchild = s->lchild;
        }
        free(s);
    }
    return TRUE;
}

/* 二叉排序树 - 删除结点操作 
   
   若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点，
   并返回TURE；否则返回FALE
 */
Status DeleteBST(BiTree *T, int key) {
    //不存在关键字等于key的数据元素
    if (!*T) {
        return FALSE;
    } else {
        //找到关键字等于key的数据元素
        if (key == (*T)->data) {
            return Delete(T);
        } else if (key < (*T)->data) {
            return DeleteBST(&(*T)->lchild, key);
        } else {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}














