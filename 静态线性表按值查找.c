#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 10

typedef struct{
	int data[MaxSize];
    int length;
}SeqList;

void InitList(SeqList *L){
    for(int i = 0;i < MaxSize;i ++){
        L->data[i] = 0;
    }
    L->length = 0;
}

void InsertList(SeqList *L,int i ,int e){
    L->data[i] = e;
    L->length ++;
}
int GetElement(SeqList L,int i){
    return L.data[i-1];
}

int main(){
    SeqList L;
    InitList(&L);
	for(int i = 0;i < 9; i++){
        InsertList(&L,i,i);
    }
	printf("%d\n",GetElement(L,5));
    return 0;
}
