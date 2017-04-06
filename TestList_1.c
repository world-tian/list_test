#include <stdio.h>

#define true 1
#define false 0
#define error 0
#define ok 1
#define MAXSIZE 20   /* 存储空间初始分配量 */

typedef struct{
	int data[MAXSIZE];  /* 数组，存储数据元素 */
	int length;   /* 线性表当前长度 */
}SqList;


//初始化线性表函数
int InitList(SqList *L){
	L->length = 0;
	return ok;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
int EmptyList(SqList L){
	if (L.length == 0)
		return true;
	else
		return false;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L){
	return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
int GetElem(SqList L,int i,int *e){
	if(L.length<0 || i<1 || i>L.length)
		return error;
	*e = L.data[i-1];
	return ok;
}


/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
int Insert(SqList *L,int i,int e){
	int k;
	if(L->length == MAXSIZE) /* 顺序线性表已经满 */
		return error;
	if(i<1 || i>L->length+1)
		return error;
	if(i <= L->length){
		for(k=L->length-1;k>=i-1;k--){
			L->data[k+1] = L->data[k];
		}	
	}
	L->data[i-1] = e;
	L->length++;
	return ok;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
int DeleList(SqList *L,int i,int *e){
	int k;
	if(L->length == 0)
		return error;
	if(i<1 || i>L->length)
		return error;
	*e = L->data[i-1];
	for(k=i;k<L->length;k++)
		L->data[k-1] = L->data[k];
	L->length--;
	return ok;
}

/* 遍历输出 */
void PrintList(SqList L){
	int i;
	for(i=1;i<=L.length;i++){
		printf("%d ",L.data[i-1]);
	}
	printf("\n");	
}

int main(){
	SqList L;
	int e, i, j, k;
	e = 0;
	i = InitList(&L);
	printf("初始化L后，L.Length = %d\n",L.length);
	for(j=0;j<5;j++)
		Insert(&L,1,j);
	printf("L赋值后，L.Length = %d\n",L.length);
	PrintList(L);
	Insert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
	PrintList(L);
	printf("L插入后，L.Length = %d\n",L.length);
	DeleList(&L,7,&e);
	if(DeleList(&L,7,&e) == error)
		printf("删除错误\n");
	else{
		printf("删除的是：%d\n",e);
		printf("删除后的结果:\n");
		PrintList(L);
	}

	return 0;
}
