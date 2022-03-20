#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MaxSize 10

//栈是只允许在一段进行插入或删除操作的线性表
//队列只允许在一端进行插入，在另一端进行删除的线性表
typedef struct{
	int data[MaxSize];
	int front,rear;
}SqQueue;
//初始化队列
void InitQUeue(SqQueue *S){
	S->front = S->rear = 0;
}
//判断队列是否为空
bool QueueEmpty(SqQueue S){
	if(S.front==S.rear){
		return true;
	}else{
		return false;
	}
}
int main(){
	SqQueue S;
	InitQUeue(&S);
	printf("%d",QueueEmpty(S));
	return 0;
}
