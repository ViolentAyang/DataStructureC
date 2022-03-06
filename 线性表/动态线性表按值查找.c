#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define InitSize 16

typedef struct{
	int *data;
    int MaxSize;
    int length;
}SeqList;

void InitList(SeqList *L){
    L->data = (int*)malloc(sizeof(int)*InitSize);
    for(int i = 0; i < L->length;i ++){
        L->data[i] = 0;
    }
    L->MaxSize = InitSize;
    L->length = 0;
}

int GetElement(SeqList L,int e){
    for(int i = 0;i < L.length;i ++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}
bool InsertList(SeqList *L,int i,int e){
    if(i<1||i>L->length+1){
        return false;
    }
	if(L->length>=L->MaxSize){
        return false;
    }
    for(int j = L->length;j>=i;j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length++;
    return true;
}
int main(){
	SeqList L;
    InitList(&L);
    for(int i = 1;i < 9; i++){
        InsertList(&L,i,i-1);
    }
    printf("查找到的结果为%d",GetElement(L,5));
    return 0;
}
