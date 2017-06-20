//
//  main.c
//  二叉树
//
//  Created by Jason on 2017/6/7.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
typedef char TElemType;
typedef struct BiNode {
    TElemType data; //节点数据
    struct BiNode *lchild, *rchild;
} BiNode, *BiTree;

/*
 *二叉树的前序遍历递归算法
 */
void PreOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

/*
 *二叉树的中序遍历递归算法
 */
void InOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

/*
 *二叉树的后序遍历递归算法
 */
void PostOrderTraverse(BiTree T) {
    if (T == NULL) {
        return;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

/**
 创建二叉树
 */
void CreateBiTree(BiTree *T) {
    TElemType ch;
    scanf("%c", &ch);
    if (ch == '\n') {
        //return;
    } else
        if (ch == '#')
            *T = NULL;
        else {
            *T = (BiTree)malloc(sizeof(BiNode));
            if (!*T) {
                exit(1);
            }
            
            (*T)->data = ch;
            CreateBiTree(&((*T)->lchild)); //创造左子树
            CreateBiTree(&((*T)->rchild)); //创造右子树
        }
}

int main(int argc, const char * argv[]) {
    
    BiTree T = NULL;
    CreateBiTree(&T);
    PreOrderTraverse(T);
    return 0;
}
