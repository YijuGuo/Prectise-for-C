#include <iostream>
using namespace std;

const int N =1e5+10;

//head表示头节点的下标（所有的节点均可用下标索引）
//e[i]表示节点i的值
//ne[i]表示节点i的next的指针是多少（节点i的下一个点的坐标）
//idx：存储当前已经用到的点(指针)
int head,e[N],ne[N],idx;

//初始化
void init()
{
    //初始时，链表为空
    head = -1;
    //idx从0号开始分配
    idx=0;
}

//将x插入到头节点后面
//插入的指针指向Head指向的点
//删除Head之前的指针，并指向插入的节点
void add_to_head(int x)
{
    //idx：当前可用的最新的点的下标
    //赋值
    e[idx]=x;
    //当前插入的节点 指向 head指向的节点
    ne[idx]=head;
    //head指向插入的节点
    head = idx;
    idx++;
}

//将x点插入下标为k的点的后面
void add(int k,int x)
{
    //赋值
    e[idx]=x;
    //指针指向节点k指向的节点
    ne[idx]=ne[k];
    //节点k指向插入的节点
    ne[k]=idx;
    idx++;
}

//单链表的删除操作：将下标是k的点后面的点删掉
void remove(int k)
{
    ne[k]=ne[ne[k]];
}




