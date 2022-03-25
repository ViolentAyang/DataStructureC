#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MaxSize 100 //定义栈中元素最大个数

typedef struct{
	char data[MaxSize];
	int top;
}SqStack;

//初始化栈
void InitStack(SqStack *S){
	S->top = -1;
}
//判断栈是否为空
bool IsEmpty(SqStack S){
	if(S.top == -1){
		return true;
	}
	return false;
}
//新元素入栈
void Push(SqStack *S,char x){
	if(S->top == MaxSize-1){
		printf("栈已满"); //栈已满
		return;
	}
	S->top += 1;
	S->data[S->top] = x;
}
//栈顶元素出栈，用x返回
void Pop(SqStack *S,char *x){
	if(S->top == -1){
		printf("栈已满");
		return;
	}
	*x = S->data[S->top];
	S->top -= 1;
}
//匹配算法
bool bracketCheck(char str[],int length){
	SqStack S;
	InitStack(&S); //初始化栈
	for(int i=0;i<length;i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			Push(&S,str[i]); //扫描到左括号就入栈
		}else{
			if(IsEmpty(S)){ //扫描到右括号，当前栈为空，即右括号单身情况
				return false; //匹配失败
			}
			char topElem; //用来保存弹出栈的栈顶元素
			Pop(&S,&topElem); //栈顶元素出栈
			if(str[i]==')'&&topElem!='('){
				return false;
			}
			if(str[i]=='}'&&topElem!='{'){
				return false;
			}
			if(str[i]==']'&&topElem!='['){
				return false;
			}
		}
	}
	return IsEmpty(S);
}
int main(){
	char s[MaxSize];
	printf("请输入需要判断的括号：\n");
	scanf("%s",s);
	int len = strlen(s);
	printf("当前输入的括号个数为：%d\n",len);
	printf("--------现在开始进行判断--------\n");
	if(bracketCheck(s,len)){
		printf("匹配成功！");
	}else{
		printf("匹配失败！");
	}
	return 0;
}
