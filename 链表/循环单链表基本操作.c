#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

typedef struct DNode{
	int data;
	struct DNode *next;
}LNode,*LinkList;

bool InitList(LinkList L){
	L = (LinkList)malloc(sizeof(LNode));
	if(!L){
		return false;
	}
	L->next = L;
	return true;
}
//判断链表是否为空
bool isEmpty(LinkList L){
	if(!L->next){
		return true;
	}
	else{
		return false;
	}
}
//判断结点p是否为循环链表的表尾结点
bool isTail(LinkList L,LNode *p){
	if(p->next==L){
		return true;
	}
	else{
		return false;
	}
}
