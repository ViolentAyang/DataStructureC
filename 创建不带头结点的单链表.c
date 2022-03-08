#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 10

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

bool InitList(LinkList *L){
    *L = NULL;
    return true;
}
bool Empty(LinkList L){
    if(L==NULL){
        return true;
    }
    else{
        return false;
    }
}
/*
bool Empty(LinkList L){
    return (L==NULL);
}
*/
int main(){
	LinkList L;
    InitList(&L);
	if(Empty(L)){
        printf("创建了一个空表");
    }else{
        printf("该表不为空");
    }
    return 0;
}
