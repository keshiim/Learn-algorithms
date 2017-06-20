//
//  平衡二叉树.c
//  算法
//
//  Created by Jason on 2017/6/20.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include "平衡二叉树.h"

// 二叉树的二叉列表几点结构定义
// 结点结构
typedef struct BiTNode {
    //结点数据
    int data;
    //结点的平衡因子
    int bf;
    //左右孩子指针
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/* 
   对以p为根的二叉排序树作右旋处理。
   处理之后p指向新的树跟结点，即旋转处理之前的左子树的跟结点
 */
void R_Rotate(BiTree *P) {
    BiTree L;
    
    // L指向P的左子树跟结点
    L = (*P)->lchild;
    // L的右子树挂接为P的左子树
    (*P)->lchild = L->rchild;
    L->rchild = (*P);
    // P指向新的跟结点
    *P = L;
}

/*
   对以P为根的二叉排序树作左旋处理。
   处理之后P指向新的树跟结点，即旋转处理之前的右子树的跟结点
 */
void L_Rotate(BiTree *P) {
    BiTree R;
    
    // R指向P的右子树跟结点
    R = (*P)->rchild;
    // R的左子树挂接为P的右子树
    (*P)->rchild = R->lchild;
    R->lchild = (*P);
    // P指向新的跟结点
    *P = R;
}

#define LH +1 //左高
#define EH 0  //等高
#define RH -1 //右高
/* 
  对以指针T所指结点为根的二叉树作左平衡旋转处理
  本算法结束时，指针T指向新的根结点
 */
void LeftBalance(BiTree *T) {
    BiTree L, Lr;
    
    // L指向T的左子树根节点
    L = (*T)->lchild;
    
    // 检查T的左子树的平衡度，并做相应平衡处理
    switch (L->bf) {
        // 新节点插入在T的左孩子的左子树上，要作单右旋处理
        case LH:
            (*T)->bf = L->bf = EH;
            R_Rotate(T);
            break;
        // 新结点插入在T的左孩子的右子树上，要作双旋处理
        case RH:
            // Lr指向T的左孩子的右子树根
            Lr = L->rchild;
            //修改T及其左孩子的平衡因子
            switch (Lr->bf) {
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
                case EH:
                    (*T)->bf = L->bf = EH;
                    break;
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
                default:
                    break;
            }
            Lr->bf = EH;
            //对T的左子树作左旋平衡处理
            L_Rotate(&(*T)->lchild);
            //对T作右旋平衡处理
            R_Rotate(T);
            break;
        default:
            break;
    }
}

/*
 对以指针T所指结点为根的二叉树作右旋平衡旋转处理
 本算法结束时，指针T指向新的根结点
 */
void RightBalance(BiTree *T) {
    BiTree R, Rl;
    R = (*T)->rchild;
    
    switch (R->bf) {
        case RH: //新结点插在T的右孩子的右子树上，要做单左旋处理
            (*T)->bf = R->bf = EH;
            L_Rotate(T);
            break;
        case LH: //新结点插在T的右孩子的左子树上，要做双旋处理
            Rl = R->lchild;
            switch (Rl->bf) {
                case LH:
                    (*T)->bf = EH;
                    R->bf = RH;
                    break;
                case EH:
                    (*T)->bf = R->bf = EH;
                case RH:
                    (*T)->bf = LH;
                    R->bf = EH;
                default:
                    break;
            }
            Rl->bf = EH;
            R_Rotate(&(*T)->rchild);
            L_Rotate(T);
        default:
            break;
    }
}




















