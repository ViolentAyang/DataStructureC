#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXLEN 255

typedef struct{
	char ch[MAXLEN];
	int length;
}SString;

int Index(SString S,SString T){
	int k = 1,i = k,j = 1;
	while(i<=S.length&&j<=T.length){
		if(S.ch[i]==T.ch[j]){
			++i;
			++j;
		}else{
			k++;
			i = k;
			j = 1;
		}
	}
	if(j>T.length){
		return k;
	}else{
		return 0;
	}
}

//字符串赋值操作
void assign(SString *S){
	printf("请输入字符串：\n");	
	char x;
	int i = 1;
	scanf("%c",&x);
	while(x!='\n'){
		S->ch[i] = x;
		i ++;
		scanf("%c",&x);
	}
	S->length = i-1;
}
//打印字符串
void printString(SString S){
	for(int i=1;i<=S.length;i++){
		printf("%c",S.ch[i]);
	}
	printf("\n");
}
int main(){
	SString S,T;
	assign(&S);
	assign(&T);
	printf("匹配:%d",Index(S,T));
	return 0;
}
