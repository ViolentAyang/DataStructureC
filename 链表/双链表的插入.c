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

//在p结点前插入s结点
bool InsertBeforeNode(DNode *p,DNode *s){
	if(p==NULL||s==NULL){
		return false;
	}
	s->next = p;
	s->prior = p->prior;
	if(p->prior){
		p->prior->next = s; 
	}
	p->prior = s;
}
//在p结点之后插入s结点
bool InsertNextNode(DNode*p,DNode *s){
	if(p==NULL||s==NULL){
		return false;
	}
	s->next = p->next;
	if(p->next){
		p->next->prior = s;
	}
	s->prior = p;
	p->next = s;
	return true;
}
void List_Print(DLinkList L){
	DLinkList p = L->next;
	printf("链表的元素为：\n");
	while(p){
		printf("%d\t",p->data);
		p = p->next;
	}
}

int main()
{
	DLinkList L;
	InitDlinkList(L);
	return 0;
}
