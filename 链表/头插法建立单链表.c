#include <stdio.h>
#include <stdlib.h> 

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

LinkList List_HeadInsert(LinkList L){
	LinkList s;
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d",&x);
	while(x!=9999){
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
}

void List_Print(LinkList L){
	LinkList p = L->next;
	printf("链表的元素为：\n");
	while(p){
		printf("%d\t",p->data);
		p = p->next;
	}
}

int main()
{
	LinkList L;
	L = List_HeadInsert(L);
	List_Print(L);
	return 0;
}
