#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MaxSize 10

struct Node{
	int data;
	int next;
};
typedef struct{
	int data;
	int next;
}SLinkList[MaxSize];
/*
	等价于
	struct Node{
	int data;
	int next;
	};
	typedef struct NodeSLinkList[MaxSize];
*/
int main(){
	//SLinkList a;//等价于 struct Node a[MaxSize];
	struct Node x;
	printf("sizeX=%d\n",sizeof(x));
	
	struct Node a[MaxSize];
	printf("sizeA=%d\n",sizeof(a));
	
	SLinkList b;
	printf("sizeB=%d\n",sizeof(b));
	
	return 0;
}
