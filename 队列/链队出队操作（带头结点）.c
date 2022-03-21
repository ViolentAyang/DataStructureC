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

//初始化队列(带头结点)
void InitQueue(LinkQueue *Q){
	Q->front = Q->rear = (LinkNode*)malloc(sizeof(LinkNode));
	Q->front->next = NULL;
}
//判断队列是否为空
bool IsEmpty(LinkQueue Q){
	if(Q.front==Q.rear){ 
		return true;
	}else{
		return false;
	}
}
//入队(带头结点)
void EnQueue(LinkQueue *Q,int x){
	LinkNode *s = (LinkNode*)malloc(sizeof(LinkNode));
	s->data = x;
	s->next = NULL;
	Q->rear->next = s;
	Q->rear = s;
}
//出队(带头结点)
bool DeQueue(LinkQueue *Q){
	if(IsEmpty(*Q)){
		printf("当前链队为空，无法出队\n");
		return false;
	}
	LinkNode *p = Q->front->next;
	int x = p->data;
	printf("当前出队的元素为：%d\n",x);
	Q->front->next = p->next;
	if(Q->rear==p){ //此次最后一个结点出队
		Q->rear = Q->front;
	}
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
