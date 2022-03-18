#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

typedef struct DNode{
	int data;
	struct DNode *next,*prior;
}DNode,*DLinkList;

bool InitDlinkList(DLinkList L){
	L = (DLinkList)malloc(sizeof(DNode));
	if(L==NULL){
		return false;
	}
	L->prior = NULL;
	L->next =NULL;
	return true;
}
//前项遍历
void forwardTraverse(DNode *p){
	while(p!=NULL){
		printf("%d",p->data);
		p = p->prior;
	}
}
//后项遍历
void afterTraverse(DNode *p){
	while(p!=NULL){
		printf("%d",p->data);
		p = p->next;
	}
} 
//前项遍历(跳过头结点)
void forwardTraverseSkipHead(DNode *p){
	while(p->prior){
		printf("%d",p->data);
		p = p->prior;
	}
}

int main()
{
	DLinkList L;
	InitDlinkList(L);
	return 0;
}
