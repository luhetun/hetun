//
// Created by ziyi wei on 2023/9/13.
//

#include <iostream>
#include "Linklist.h"
#include <cstdlib>
using namespace std;

//链表初始化
slink *initList(){
    slink *L;
    L=(slink *) malloc(sizeof(slink));//分配地址空间
    if(L==nullptr){
        printf(("overflow!"));
        exit(1);
    }
    L->next=nullptr;//指针指向空
    return L;
}

//创建链表(尾插法，提示以-9999结尾)
slink *createFromTail(){
    slink *L,*r,*s;//r始终指向链表尾部
    ElemType x;
    L=initList();//初始化为空表
    r=L;
    cin>>x;
    while(x!=-9999){
        s=(slink*) malloc(sizeof (slink));
        s->data=x;//给集合赋值
        r->next=s;//插入新节点
        r=s;//指向链表尾部
        cin>>x;//输入下一个元素
    }
    r->next=nullptr;
    return L;
}

//链表插入（尾插法）
slink *insertElem(slink *L,int i,ElemType x){
    slink *p,*q;
    int j = 0;
    p=L;
    if(i<1)return 0;
    while(p&&j<i-1){
        p=p->next;
        j++;
    }//寻找所插位置
    if(!p)return 0;
    q=(slink*) malloc(sizeof (slink));
    q->data=x;
    q->next=p->next;//q连上下一个节点
    p->next=q;//q的前一个节点与q相连
    return L;
}

//链表删除
slink *deleteElem(slink *L,int i,ElemType *x){
    slink *p,*q;
    int j = 0;
    p=L;
    if(i<1)return 0;
    while(p&&j<i-1){
        p=p->next;
        j++;
    }//寻找所删节点
    if(!p->next)return 0;
    q=p->next;//q指向待删节点；
    p->next=q->next;//前一个节点与后一个节点相连
    *x=q->data;//x存储所删数据
    free(q);//释放节点
    return L;
}

//求链表长度
int length(slink *L){
    slink *p=L;
    int length=0;
    while(p){
        p=p->next;
        ++length;
    }
    return length-1;
}

//链表排序
slink *Sort(slink *L) {
    int len= length(L);
    slink *p, *q,*t; // 声明节点指针变量 p 和 q
    int i;
    t = (slink*)malloc(sizeof(slink)); // 创建临时节点 t

    for (i = 0; i < len; i++) {
        p = L->next; // 将p指向为链表的第一个节点
        q = p->next; // 将q指向为p的下一个节点
        while (q) {// 当q不为NULL时执行循环
            if (q->data < p->data) {// 进行值交换
                t->data = q->data; // 将q的值保存到临时节点t
                q->data = p->data; // 将p的值赋给q
                p->data = t->data; // 将t中保存的值赋给p
            }
            p = q; // 更新p为下一个节点
            q = p->next; // q为p的下一个节点
        }
    }
    free(t); // 释放临时节点 t 的内存空间
    return L; // 返回排序成功的标识
}

void display(slink *L){

    slink *p;
    p=L->next;
    if(!p)
        cout<<"Ø";
    while (p){
        cout<<p->data<<" ";
        cout.flush();
        p=p->next;
    }
    cout << endl;
}


