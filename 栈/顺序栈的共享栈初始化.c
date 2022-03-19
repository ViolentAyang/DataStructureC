#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MaxSize 10

typedef struct{
	int data[MaxSize];  //静态数组存放栈中元素
	int top0;  //0号栈栈顶指针
	int top1;  //1号栈栈顶指针
}ShStack;

//初始化栈
void InitStack(ShStack *S){
	S->top0 = -1;
	S->top1 = MaxSize;
}
//栈满
bool fillStack(ShStack S){
	if(S.top0+1==S.top1){
		return true;
	}else{
		return false;
	}
}

int main(){
	ShStack S;
	InitStack(&S);
	printf("%d",fillStack(S));
	return 0;
}
