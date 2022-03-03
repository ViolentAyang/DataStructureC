#include<stdio.h>
#define Maxsize 10

typedef struct{
	int data[Maxsize];
	int length;
}SqList;

void InitList(SqList *L){
	for(int i = 0;i < Maxsize;i ++ ){
		L->data[i] = 0;
	}
	L->length = 0;
}

int main(){
	SqList L;
	InitList(&L);
	for(int i = 0;i< Maxsize;i++){
		printf("data[%d]=%d\n",i,L.data[i]);
	} 
	return 0;
} 
