#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*rchild; 
}BiTNode,*BiTree;

void InitTree(BiTree T,int m){
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = m;
	T->lchild = NULL;
	T->rchild = NULL;
}

void visit(BiTree T){
	printf("%d\t",T->data);
}

//前序遍历
void PreOrder(BiTree T){
	if(T!=NULL){
		visit(T);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}

//中序遍历
void InOrder(BiTree T){
	if(T!=NULL){
		InOrder(T->lchild);
		visit(T);
		InOrder(T->rchild);
	}
}

//后序遍历
void PostOrder(BiTree T){
	if(T!=NULL){
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		visit(T);
	}
}

int main(){
	
	return 0;
}
