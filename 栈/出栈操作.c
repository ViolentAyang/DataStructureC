#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MaxSize 10

typedef struct{
	int data[MaxSize];  //静态数组存放栈中元素
	int top;  //栈顶指针
}SqStack;

//初始化栈
void InitStack(SqStack *S){
	S->top = -1;
}
//新元素进栈
bool Push(SqStack *S,int x){
	if(S->top==MaxSize-1){
		return false;
	}
	S->top += 1;
	S->data[S->top] = x;
	return true;
}
//出栈操作
int Pop(SqStack *S,int x){
	if(S->top==-1){
		return false;
	}
	x = S->data[S->top];
	S->top -= 1;
	return x;
}
//打印
void PrintStack(SqStack S){
	if(S.top==-1){
		printf("栈为空！");
	}
	for(int i=0;i<=S.top;i++){
		printf("%d\n",S.data[i]);
	}
}
int main(){
	SqStack S;
	InitStack(&S);
	Push(&S,1);
	Push(&S,2);
	Push(&S,3);
	Push(&S,4);
	Push(&S,5);
	PrintStack(S);
	printf("%d\n",Pop(&S,-1));
	PrintStack(S);
	return 0;
}
