//
// Created by ziyi wei on 2023/9/13.
//

#ifndef LIANBIAO1_LINKLIST_H
#define LIANBIAO1_LINKLIST_H

#include <iostream>

//结构定义
typedef int ElemType;//以便后续修改集合内数据类型
typedef struct node{
    ElemType data;
    struct node *next;
}slink;

//函数原型
void display(slink *L);
slink *initList();
slink *createFromTail();
slink *insertElem(slink *L,int i,ElemType x);
slink *deleteElem(slink *L,int i,ElemType *x);
int length(slink *L);
slink *Sort(slink *L);//排序
slink *Union(slink *la,slink *lb, slink *lc);//并集
slink *InterSect(slink *la,slink *lb, slink *lc);//交集
slink *Subs(slink *la,slink *lb, slink *lc);//差集


#endif //LIANBIAO1_LINKLIST_H
