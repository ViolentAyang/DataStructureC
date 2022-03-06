#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10

typedef struct{
	int *data;
    int length;
}SeqList;

void ListInsert(SeqList *L,int i,int e){
    for(int j = L->length;j>=i;j--){
        L->data[j] = L->data[j-1];
    }
    L->data[i-1] = e;
    L->length ++;
}
void InitList(SeqList *L){
	L->data = (int*)malloc(sizeof(int)*MaxSize);
    L->length = 0;
}
void PrintList(SeqList L){
	for(int i = 0;i <L.length;i++){
		printf("%d\n",L.data[i]);
    }
}
int main(){
	SeqList L;
    InitList(&L);
    L.data[0] = 0;
    L.length++;
    L.data[1] = 1;
    L.length++;
    L.data[2] = 2;
    L.length++;
    L.data[3] = 3;
    L.length++;
    L.data[4] = 4;
    L.length++;
    PrintList(L);
    ListInsert(&L,3,3);
    PrintList(L);
    return 0;
}
