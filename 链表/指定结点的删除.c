#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//这种方法不适合删除最后一个结点，如需删除最后一个结点仍需从头遍历

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
bool DeleteNode(LNode *p){
	if(!p){
		return false;
	}
	LNode *q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
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
    int m; 
    printf("----测试----\n");
    LNode *t = L->next->next;
    DeleteNode(t);
    PrintList(L);
    return 0;
}
