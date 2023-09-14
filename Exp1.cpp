//
// Created by ziyi wei on 2023/9/13.
//
#include <iostream>
#include "Linklist.h"
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
using namespace std;

slink *InterSect(slink *la,slink *lb, slink *lc){//交集，哈希表
    slink *p,*r,*k;
    p=la;//指向集合A
    r=lc;//新的集合C
    //slink *hashTable[100]={NULL};//创建哈希表
    unordered_map<int,slink*>hashTable;
    while(p){//在哈希表中记录集合A的数据
        hashTable[p->data]=p;
        p=p->next;
    }
    p=lb->next;//指向集合B的第一个节点
    while(p){//遍历集合B查询是否存在相同元素
        if(hashTable.find(p->data)!=hashTable.end())//查询哈希表是否有相同元素
        {
            k=new slink ;
            k->data=p->data;//将该元素的值赋给新节点
            k->next=nullptr;
            r->next=k;//在新集合中插入节点k
            r=k;//指向尾部元素
        }
        p=p->next;
    }
    return lc;
}

slink *Union(slink *la,slink *lb, slink *lc){//并集，哈希表
    slink *p,*r,*k;
    p=la->next;//指向集合A的第一个节点
    r=lc;//新的集合C
    unordered_set<int> hash;//创建哈希表
    while(p){
        //创建哈希表，并将la中的元素添加到在lc链表里
        hash.insert(p->data);//在哈希表中记录集合A的数据
        k=new slink ;
        k->data=p->data;//将该元素的值赋给新节点
        k->next=nullptr;
        r->next=k;//在新集合中插入节点k
        r=k;//指向尾部元素
        p=p->next;
    }
    p=lb->next;//指向集合B的第一个节点
    while(p){//遍历集合B查询是否存在相同元素,若不存在则添加，存在则跳过
        if(hash.find(p->data)==hash.end())//查询哈希表是否没有相同元素，若没有，find和end都返回容器末尾
        {
            k=new slink ;
            k->data=p->data;//将该元素的值赋给新节点
            k->next=nullptr;
            r->next=k;//在新集合中插入节点k
            r=k;//指向尾部元素
        }
        p=p->next;
    }
    return lc;
}

slink *Subs(slink *la,slink *lb, slink *lc) {//差集A-B，哈希表
    slink *p, *r, *k;
    p = lb->next;//指向集合B的第一个节点
    r = lc;//新的集合C
    //slink *hashTable[100] = {nullptr};//创建哈希表
    unordered_map<int,slink*>hashTable;
    while (p) {//在哈希表中记录集合A的数据
        hashTable[p->data] = p;
        p = p->next;
    }
    p = la->next;//指向集合A的第一个节点
    while (p) {//遍历集合A查询是否存在相同元素
        if(hashTable.find(p->data)==hashTable.end())//查询哈希表是否有相同元素，如果不同则存到集合C
        {
            k=new slink ;
            k->data = p->data;//将该元素的值赋给新节点
            k->next = nullptr;
            r->next = k;//在新集合中插入节点k
            r = k;//指向尾部元素
        }
        p = p->next;
    }
    return lc;
}

int main(){
    //初始化链表
    slink *la=initList();
    slink *lb=initList();
    slink *lc=initList();
    //构造链表la和lb
    cout<<"请输入集合A，以空格分隔，-9999结尾";
    la=createFromTail();
    cout<<"请输入集合B，以空格分隔，-9999结尾";
    lb=createFromTail();
    cout<<"集合A排序后的结果为：";
    cout.flush();
    display(Sort(la));
    cout<<"集合B排序后的结果为：";
    cout.flush();
    display(Sort(lb));
    cout<<"集合A与集合B的并集为：";
    cout.flush();
    lc=Union(la,lb,lc);
    display(lc);
    lc = initList();
    cout<<"集合A与集合B的交集为：";
    cout.flush();
    lc=InterSect(la,lb,lc);
    display(lc);
    lc = initList();
    cout<<"集合A与集合B的差集为：";
    cout.flush();
    lc=Subs(la,lb,lc);
    display(lc);
}
