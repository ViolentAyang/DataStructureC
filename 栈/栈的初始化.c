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
//判断栈空
bool StackEmpty(SqStack s){
	if(S.top==-1){
		return false;
	}else{
		return true;
	}
}
int main(){
	SqStack S;
	InitStack(&S);
	printf("%d",StackEmpty(S));
	return 0;
}
