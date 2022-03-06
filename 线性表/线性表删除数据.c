#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSzie 10

typedef struct{
	int *data;
    int length;
}SeqList;

void InitList(SeqList *L){
    L->data = (int*)malloc(sizeof(int)*MaxSzie);
    L->length = 0;
}

bool InsertList(SeqList *L,int i,int e){
    if(i<1||i>L->length+1){
        return false;
    }
	if(L->length>=MaxSzie){
        return false;
    }
    for(int j = L->length;j>=i;j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return true;
}

bool DeleteList(SeqList *L,int i,int *e){
	if(i<1||i>L->length){
    	return false;
    }
    *e = L->data[i-1];
    for(int j = i;j<L->length;j++){
        L->data[j-1] = L->data[j]; 
    }
    L->length --;
    return true;
}

void PrintList(SeqList L){
    for(int i = 0;i < L.length;i ++){
        printf("%d\n",L.data[i]);
    }
}

int main(){
    SeqList L;
    InitList(&L);
    for(int i = 0;i < 5; i++){
        InsertList(&L,i,i);
    }
    PrintList(L);
    int e = -1;
    if(DeleteList(&L,3,&e)){
        printf("已删除第3个元素，删除元素值为%d\n",e);
    }
    else{
        printf("位序i不合法，删除失败\n");
    }
    PrintList(L);
    return 0;
}
