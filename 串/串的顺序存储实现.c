#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXLEN 255 //预定义最大串长为255

//串的顺序存储 静态数组实现(定长顺序实现)
typedef struct{
	char ch[MAXLEN]; //每个分量存储一个字符 分配连续的存储空间，每个char字符占1B
	int length; //串的实际长度
}SString;
//动态数组实现(堆分配存储)
typedef struct{
	char *ch; //按串长分配存储区，ch指向串的基地址
	int length; //串的长度
}HString;

int main(){
	HString S;
	S.ch = (char *)malloc(sizeof(char)); //用完需要手动free
	return 0;
}
//四种方案
//第一种方法 定义一个字符串数组 加上一个记录长度的length变量
//第二种方法 ch[0]充当length 优点：字符串的位序和数组下标相同 缺点：只能表示0-255的长度
//第三种方法 没有length变量 以字符'\0'表示结尾（对应ASCII码中的0） 缺点：想知道长度需要遍历
//第四种方法 舍弃第一个位置 加上一个length变量
