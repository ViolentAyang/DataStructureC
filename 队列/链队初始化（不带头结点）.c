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
	//初始时 front、rear都指向NULL
	Q->front = NULL;
	Q->rear = NULL;
}
//判断队列是否为空
bool IsEmpty(LinkQueue Q){
	if(Q.front==NULL){ //或者Q.rear==NULL
		return true;
	}else{
		return false;
	}
}
int main(){
	LinkQueue Q;
	InitQueue(&Q);
	printf("队列是否为空：%d",IsEmpty(Q));
	return 0;
}
