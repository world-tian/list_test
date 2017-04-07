#include "stdio.h"
#include "stdlib.h"
#include "time.h"


#define ok 1
#define error 0
#define true 1
#define false 0

#define MAXSIZE 20  //存储空间初始分配量


/* 线性表的单链表存储结构 */
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; //定义LinkList

//初始化
int InitList(LinkList *L){
	*L = (LinkList)malloc(sizeof(Node));
	if(!(*L))
		return error;
	(*L)->next = NULL;
	return ok;
}
//初始化后求长度
int ListLength(LinkList L){
	int i = 0;
	LinkList p = L->next;
	while(p){
		i++;
		p = p->next;
	}
	return i;
}
//插入数
int ListInsert(LinkList *L,int i,int e){
	int j;
	LinkList p,s;
	p = *L;
	j = 1;
	while(p && j<i){
		p = p->next;
		++j;
	}
	if(!p || j>i)
		return error;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return ok;
}
//删除节点
int DeleList(LinkList *L,int i,int *e){
	int j = 1;
	LinkList p = *L;
	LinkList q;
	while(p->next && j<i){
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i)
		return error;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return ok;
}
//打印数
void PrintData(LinkList L){
	int i;
	LinkList p;
	p = L->next;
	printf("打印链表：");
	while(p){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}
//头插法整表创建
void CreateHeadList(LinkList *L,int n){
	LinkList p;
	int i = 0;
	srand(time(0));//产生随机种子
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for(i;i<n;i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}
}
//尾插法
void CreatListtail(LinkList *L,int n){
	LinkList p,r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for(i=0;i<n;i++){
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand()%100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
//删除表
int ClearList(LinkList *L){
	LinkList p, r;
	p = (*L)->next;
	while(p){
		r = p->next;
		free(p);
		p = r;
	}
	(*L)->next=NULL; 
	return ok;
}
int main(){
	int k,e;
	LinkList L;
	LinkList T;
	InitList(&L);
	printf("初始化后的长度：%d\n",ListLength(L));
	for(k=0;k<5;k++)
		ListInsert(&L,1,k);
	printf("插入后的长度：%d\n",ListLength(L));
	PrintData(L);
	ListInsert(&L,5,10);
	PrintData(L);
	DeleList(&L,4,&e);
	printf("删除的元素：%d\n",e);
	PrintData(L);
	CreateHeadList(&T,20);
    printf("整体创建T的元素(头插法)：");
    PrintData(T);
	ClearList(&T);
	printf("清空后的长度：%d\n",ListLength(T));
	CreatListtail(&L,30);
	printf("整体创建L的元素(尾插法)：");
	PrintData(L);
	return 0;
}
