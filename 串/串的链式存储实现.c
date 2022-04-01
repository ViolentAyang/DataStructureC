#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StringNode{
	char ch; //每个结点存一个字符
	struct StringNode *next; //每个指针占用四个字符 存储密度低
}StringNode,*String; 

typedef struct StringNode{
	char ch[4]; //每个结点存多个字符
	struct StringNode *next; 
}StringNode,*String; //存储密度提高

int main(){
	String S;
	return 0;
}
