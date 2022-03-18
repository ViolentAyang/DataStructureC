#include <stdio.h>
#include <stdlib.h> 

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

LinkList List_TailInsert(LinkList L){
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LinkList s,r = L;
	scanf("%d",&x);
	while(x!=9999){
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	r ->next = NULL;
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
	L = List_TailInsert(L);
	List_Print(L);
	return 0;
}
