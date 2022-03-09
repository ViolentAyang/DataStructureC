#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList; 

bool InitList(LinkList *L){
	(*L) = NULL;
	return true;
}
void PrintList(LinkList L){
	LinkList p = L;
	while(p){
		printf("%d\n",p->data);
		p = p->next;
	}
}
int Length(LinkList L){
	LNode *p = L;
	int j = 0;
	while(p){
		p = p->next;
		j++;
	}
	return j;
}
bool InsertList(LinkList *L,int i,int e){
	if(i<1){
		return false;
	}
	if(i==1){
		LNode *s = (LNode*)malloc(sizeof(LNode));
		s->data = e;
		s->next = *L;
		*L = s;
		return true;
	}
	LNode *p;
	int j = 1;
	p = *L;
	while(p&&j<i-1){
		p = p->next;
		j++;
	}
	if(p==NULL){
		return false;
	}
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
int main(){
	LinkList L;
	InitList(&L);
	for(int i = 0;i < 10;i ++){
		InsertList(&L,i+1,i);
	}
	PrintList(L);
	printf("----测试----\n");
	printf("该链表的长度为%d",Length(L));
	return 0;
}
