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

bool DeleteNextNode(DNode *p){
	if(!p){
		return false;
	}
	DNode* q = p;
	if(!q){
		return false;
	}
	p->next = q->next;
	if(q->next){
		q->next->prior = p;
	}
	free(p);
	return true;
}

int main()
{
	DLinkList L;
	InitDlinkList(L);
	return 0;
}
