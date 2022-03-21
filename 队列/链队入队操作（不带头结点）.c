#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MaxSize 10

typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode;
typedef struct LinkQueue{
	LinkNode *front,*rear;
}LinkQueue;

//初始化队列(不带头结点)
void InitQueue(LinkQueue *Q){
	Q->front = NULL;
	Q->rear= NULL;
}
//入队(不带头结点)
void EnQueue(LinkQueue *Q,int x){
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if(Q->front==NULL){
		Q->front = s;
		Q->rear = s;
	}else{
		Q->rear->next = s;
		Q->rear = s;
	}
}
//判断队列是否为空
bool IsEmpty(LinkQueue Q){
	if(Q.front==NULL){ 
		return true;
	}else{
		return false;
	}
}
int main(){
	LinkQueue Q;
	InitQueue(&Q);
	printf("队列是否为空：%d\n",IsEmpty(Q));
	EnQueue(&Q,100);
	printf("当前队尾元素：%d\n",Q.rear->data);
	printf("队列是否为空：%d\n",IsEmpty(Q));
	return 0;
}
