#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct ElemType{
	int value;
}ElemType;

typedef struct BiTNnode{
    ElemType data;
	struct BiTNnode *lchild,*rchild;//左右孩子指针
	//struct BiTNnode *parent;//父节点指针
}BiTNnode,*BiTree;

int main(){
	//定义一棵树
	BiTree root = NULL;
	//插入根结点
	root = (BiTree)malloc(sizeof(BiTNnode));
	root->data = {1};
	root->lchild = NULL;
	root->rchild = NULL;
	//插入新结点
	BiTNnode *p = (BiTree)malloc(sizeof(BiTNnode));
	p->data = {2};
	p->lchild = NULL;
	p->rchild = NULL;
	root->lchild = p;
	return 0;
}

