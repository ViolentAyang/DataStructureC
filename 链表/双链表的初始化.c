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
