//
//  main.c
//  线索二叉树
//
//  Created by Jason on 2017/6/7.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>

/*
 * 二叉树的二叉线索存储结构定义
 Link == 0表示执行左右孩子指针
 Thread == 1表示执行前驱或后继的线索
 */
typedef enum {
    Link,
    Thread
} PointerTag;

typedef char TElemType;

typedef struct BiThrNode {
    //结点数据
    TElemType data;
    
    /* 左右孩子指针*/
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;

BiThrTree pre; //全局变量，之中执行刚刚访问过的结点
/// 中序遍历进行中序线索化
void inThreadding(BiThrTree p) {
    if (p) {
        //递归左字数线索化
        inThreadding(p->lchild);
        if (!p->lchild) {
            //没有左孩子
            p->LTag = Thread;
            //左孩子指针指向前驱
            p->lchild = pre;
        }
        
        if (!pre->rchild) {
            //前驱没有右孩子
            pre->RTag = Thread; //后继线索
            pre->rchild = p; // 前驱右孩子指针指向后继(当前结点P)
        }
        
        //保持pre指向p的前驱
        pre = p;
        //递归右子树线索化
        inThreadding(p->rchild);
    }
}

typedef enum {
    ERROR,
    OK,
} Status;
/*
 * T指向头结点，头结点左链lchild指向根节点
 * 头结点右链rchild指向中序遍历的左右一个结点。
 * 中序遍历二叉线索链表表示的二叉树T
*/
Status InOrderTraverse_Thr(BiThrTree T) {
    BiThrTree p;
    //p指向根节点
    p = T->lchild;
    
    //空树或遍历结束时，P==T
    while (p != T) {
        //当LTag == Link时循环到中序序列第一个结点
        while (p->LTag == Link) {
            p = p->lchild;
        }
        
        printf("%c", p->data);
        
        while (p->RTag == Thread && p->rchild != T) {
            p = p->rchild;
            printf("%c", p->data);
        }
        
        p = p->rchild;//P指向其右子树根
    }
    return OK;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
