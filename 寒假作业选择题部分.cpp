#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a[] = { 2, 4, 6, 8, 10 }, *p, **k;
	p = a;
	k = &p;
	printf(" % d", *(p++));//2
	//p++֮�󷵻صĻ���p��λ�ã�������Ȼ��2
	printf(" % d\n", **k);//4
	//����p�Ѿ���1�ˣ�����**k����4
	return 0;
}


int main1()
{
	short i = 65537;
	int j = i + 1;
	printf("i = %d,j = %d", i, j);//1,2
	//short��ʾ�ķ�Χ��-32768 - +32767��unsigned short�ķ�Χ��0~65535
	//65537��int���͵ı�ʾΪ00000000 00000001 00000000 00000001
	//ת����short���ͻ�ȱʧ�����ֽڣ��ͱ���� 1


	return 0;
}