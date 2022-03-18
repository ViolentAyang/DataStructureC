#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

typedef struct DNode{
	int data;
	struct DNode *next,*prior;
}DNode,*DLinkList;

bool InitList(DLinkList L){
	L = (DLinkList)malloc(sizeof(DNode));
	if(!L){
		return false;
	}
	L->next = L;
	L->prior = L;
	return true;
}
//判断链表是否为空
bool isEmpty(DLinkList L){
	if(!L->next){
		return true;
	}
	else{
		return false;
	}
}
//判断结点p是否为循环链表的表尾结点
bool isTail(DLinkList L,DNode *p){
	if(p->next==L){
		return true;
	}
	else{
		return false;
	}
}
//在p结点之后插入s结点
void InsertNextDNode(DNode* p,DNode* s){
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next =s;
}
//删除p的后继节点
void DeleteAfterDNode(DNode *p){
	DNode *q = p->next;
	p->next = q->next;
	q->next->prior = p;
	free(q);
}
