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

bool Empty(LinkList L){
    if(L->next==NULL){
        return true;
    }else{
        return false;
    }
}

int main(){
	LinkList L;
    InitList(&L);
    if(Empty(L)){
        printf("分配成功");
    }else{
        printf("分配失败");
    }
    return 0;
}
