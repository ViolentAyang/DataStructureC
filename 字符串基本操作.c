#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXLEN 255

typedef struct{
	char ch[MAXLEN];
	int length;
}SString;

//求子串 用Sub返回串S的第pos个字符起长度为len的子串
bool SubString(SString *Sub,SString S,int pos,int len){
	if(pos+len-1>S.length){
		return false;
	}
	for(int i=pos;i<pos+len;i++){
		Sub->ch[i-pos+1] = S.ch[i];
	}
	Sub->length = len;
	return true;
}
//比较操作 若S>T,则返回值>0；若S=T，则返回值=0；若S<T，则返回值<0
int StrCompare(SString S,SString T){
	for(int i=0;i<=S.length&&i<T.length;i++){
		if(S.ch[i]!=T.ch[i]){
			return S.ch[i] - T.ch[i];
		}
	}
	//扫描到所有字符都相同，则长度长的串更大
	return S.length - T.length;
}
//定位操作 若主串S中存在与串T值相同的子串，则返回它在主串S中第一次出现的位置，否则函数值为0
int Index(SString S,SString T){
	int i = 1,n = S.length,m = T.length;
	SString Sub; //用于暂存子串
	while(i<=n-m+1){
		SubString(&Sub,S,i,m);
		if(StrCompare(Sub,T)!=0){
			++i;
		}else{
			return i; //返回子串在主串中的位置
		}
	}
	return 0; //S中不存在与T相等的子串
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
	printf("求子串操作：\n");
	SString Sub;
	SubString(&Sub,S,2,3);
	printString(Sub);
	printf("比较操作：\n");
	printf("S串和T串是否相等：%d\n",StrCompare(S,T));
	printf("定位操作：\n");
	printf("出现位置:%d",Index(S,T));
	return 0;
}
