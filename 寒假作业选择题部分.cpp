#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a[] = { 2, 4, 6, 8, 10 }, *p, **k;
	p = a;
	k = &p;
	printf(" % d", *(p++));//2
	//p++之后返回的还是p的位置，所以仍然是2
	printf(" % d\n", **k);//4
	//现在p已经加1了，所以**k就是4
	return 0;
}


int main1()
{
	short i = 65537;
	int j = i + 1;
	printf("i = %d,j = %d", i, j);//1,2
	//short表示的范围是-32768 - +32767，unsigned short的范围是0~65535
	//65537的int类型的表示为00000000 00000001 00000000 00000001
	//转换成short类型会缺失两个字节，就变成了 1


	return 0;
}