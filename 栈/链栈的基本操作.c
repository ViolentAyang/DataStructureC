#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MaxSize 10

typedef struct Linknode{
	int data;
	struct Linknode *next;
}LiNode,*LiStack;

//初始化
bool InitLiStack(LiStack L){
	L = (LiStack)malloc(sizeof(LiNode));
	L->next = NULL;
	return true;
}
//入栈
void Push(LiStack L,int x){
	LiStack s = (LiStack)malloc(sizeof(LiNode));
	s->data = x;
	s->next = L->next;
	L->next = s;
}
//出栈
void Pop(LiStack L,int x){
	LiNode *s = L->next;
	x = s->data;
	printf("弹出的元素为:%d\n",x);
	L->next = s->next;
	free(s);
}
int main(){
	LiNode L;
	InitLiStack(&L);
	Push(&L,1);
	Push(&L,3);
	Push(&L,4);
	Push(&L,5);
	Push(&L,6);
	Pop(&L,-1);
	Pop(&L,-1);
	Pop(&L,-1);
	Pop(&L,-1);
	return 0;
}
