#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node *next;
}LinkNode;
typedef struct Queue{
	LinkNode *front,*rear;
}LinkQueue;

//初始化队列(不带头结点)
void InitQueue(LinkQueue *Q){
	Q->front = NULL;
	Q->rear = NULL;
}
//判断队列是否为空
bool IsEmpty(LinkQueue Q){
	if(Q.front==NULL){ 
		return true;
	}else{
		return false;
	}
}
//入队(不带头结点)
void EnQueue(LinkQueue *Q,int x){
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	if(IsEmpty(*Q)){
		Q->rear = s;
		Q->front = s;
	}else{
		Q->rear->next = s;
		Q->rear = s;
	}
}
//出队(不带头结点)
bool DeQueue(LinkQueue *Q){
	if(IsEmpty(*Q)){
		printf("当前链队为空，无法出队\n");
		return false;
	}
	LinkNode *p = Q->front;
	int x = p->data;
	printf("当前出队的元素为：%d\n",x);
	Q->front = p->next;
	free(p);
	return true;
}

int main(){
	LinkQueue Q;
	InitQueue(&Q);
	printf("队列是否为空：%d\n",IsEmpty(Q));
	for(int i=0;i<=10;i++){
		EnQueue(&Q,i);
	}
	for(int i=0;i<=11;i++){
		DeQueue(&Q);
	}
	printf("队列是否为空：%d\n",IsEmpty(Q));
	return 0;
}
