#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXLEN 255

typedef struct{
	char ch[MAXLEN];
	int length;
}SString;

//输入字符串
void assign(SString *S){
	int i = 1;
	char x;
	scanf("%c",&x);
	while(x!='\n'){
		S->ch[i++] = x;
		scanf("%c",&x);
	}
	S->length = i-1;
}
//打印字符串
void print(SString S){
	for(int i=1;i<=S.length;i++){
		printf("%c",S.ch[i]);
	}
	printf("\n");
}
//求next数组
void getNext(SString S,int *next){
	next[1] = 0;
	int i = 1,j = 0;
	while(i<S.length){
		if(j==0||S.ch[i]==S.ch[j]){
			next[++i] = ++j;
		}else{
			j = next[j];
		}
	}
}
//kmp代码
int KMP(SString S,SString T){
	int i=1,j=1;
	int next[T.length+1];
	getNext(T,next);
	while(i<=S.length&&j<=T.length){
		if(j==0||S.ch[i]==T.ch[j]){
			++i;
			++j;
		}else{
			j = next[j];
		}
	}
	if(j>T.length){
		return i-T.length;
	}else{
		return 0;
	}
}
int main(){
	SString S,T;
	printf("请输入主串：\n");
	assign(&S);
	printf("请输入模式串：\n");
	assign(&T);
	printf("匹配到的位置:%d",KMP(S,T));
	return 0;
}
