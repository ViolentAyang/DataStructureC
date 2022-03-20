#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MaxSize 10

//栈是只允许在一段进行插入或删除操作的线性表
//队列只允许在一端进行插入，在另一端进行删除的线性表
//这里的顺序队列以循环队列为例

typedef struct{
	int data[MaxSize];
	int front,rear;
}SqQueue;
//初始化队列
void InitQUeue(SqQueue *S){
	S->front = S->rear = 0;
}
//判断队列是否满
bool QueueFull(SqQueue S){
	if((S.rear+1)%MaxSize==S.front){
		return true;
	}
	return false;
}
//判断队列是否为空
bool QueueEmpty(SqQueue S){
	if(S.front==S.rear){
		return true;
	}else{
		return false;
	}
}
//入队操作
bool EnQueue(SqQueue *S,int x){
	if(QueueFull(*S)){
		return false;
	}
	S->data[S->rear] = x;
	S->rear = (S->rear+1)%MaxSize;
	return true;
}
//出队操作
bool DeQueue(SqQueue *S,int* x){
	if(QueueEmpty(*S)){
		return false;
	}
	*x = S->data[S->front];
	S->front = (S->front+1)%MaxSize;
	return true;
}
void PrintQueue(SqQueue S){
	for(int i=S.front;i<S.rear;i++){
		printf("%d\n",S.data[i]);
	}
}
int main(){
	SqQueue S;
	InitQUeue(&S);
	int x=0;
	printf("是否为空：%d\n",QueueEmpty(S));
	EnQueue(&S,1);
	EnQueue(&S,2);
	EnQueue(&S,3);
	EnQueue(&S,4);
	EnQueue(&S,5);
	EnQueue(&S,6);
	EnQueue(&S,7);
	EnQueue(&S,8);
	EnQueue(&S,9);
	PrintQueue(S);
	printf("是否为满:%d\n",QueueFull(S));
	printf("是否为空:%d\n",QueueEmpty(S));
	printf("当前队尾元素:%d\n",S.data[S.rear-1]);
	DeQueue(&S,&x);
	printf("当前出队的元素为:%d\n",x);
	DeQueue(&S,&x);
	printf("当前出队的元素为:%d\n",x);
	DeQueue(&S,&x);
	printf("当前出队的元素为:%d\n",x);
	printf("是否为满:%d\n",QueueFull(S));
	printf("是否为空:%d\n",QueueEmpty(S));
	PrintQueue(S);
	return 0;
}
