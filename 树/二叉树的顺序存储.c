#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MaxSize 100

typedef struct TreeNode{
	int value;
	bool isEmpty;
}TreeNode;

TreeNode* InitTree(){
	TreeNode t[MaxSize];
	for(int i=0;i<MaxSize;i++){
		t[i].isEmpty = true;
	}
	return t;
}

int main(){
	TreeNode *t = InitTree();
	return 0;
}
