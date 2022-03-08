#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList *L){
	(*L) = (LNode*)malloc(sizeof(LNode));
    if(L==NULL){
        return false;
    }
	(*L)->next = NULL;
    return true;
}
bool ListInsert(LinkList *L,int i,int e){
    if(i<1){
        return false;
    }
    LNode *p;
    int j = 0;
    p = *L;
    while(p&&j<i-1){
        p = p->next;
        j ++;
    }
    if(p == NULL){
        return false;
    }
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next=p->next;
    p->next=s;
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
    for(int j=0;j<10;j++){
        ListInsert(&L,j+1,j);
    }
    PrintList(L);
    printf("-------测试-------\n");
  	ListInsert(&L,5,66); 
    PrintList(L);
    return 0;
}
