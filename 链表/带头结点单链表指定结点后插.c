#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList *L){
    (*L) = (LNode*)malloc(sizeof(LNode));
    if(*L==NULL){
        return false;
    }
    (*L)->next = NULL;
	return true;
}
bool InsertList(LinkList *L,int i,int e){
	if(i<1){
		return false;
	}
	LNode *p;
	p = *L;
	int j = 0;
	while(p&&j<i-1){
		p = p->next;
		j++;
	}
	if(!p){
		return false;
	}
	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}
bool InsertAfterNode(LNode *s,int e){
	if(!s){
		return false;
	}
	LNode *t = (LNode*)malloc(sizeof(LNode));
	if(!t){
		return false;
	}
	t->data = e;
	t->next = s->next;
	s->next = t;
	return true;
}
void PrintList(LinkList L){
	LinkList p = L->next;
	while(p){
		printf("%d\n",p->data);
		p = p->next;
	}
}
int main(){
	LinkList L;
    InitList(&L);
    for(int i = 0;i < 10;i ++){
    	InsertList(&L,i+1,i);
    }
    PrintList(L);
    LNode *p = L->next->next;
    printf("----测试----\n");
    InsertAfterNode(p,66);
    PrintList(L);
    return 0;
}
