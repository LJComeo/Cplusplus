#include <stdio.h>

#define N (6561) //�����ַ���8��λ�õ����п��ܵ�����


int num[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
char symbol[3] = { ' ', '+', '-' };

int No_next(int i, int n)//��ȡ��ǰ���ֵĴ�С
{
	int sum = 0;
	for (;i <= n; ++i)
		sum = sum * 10 + num[i];
	return sum;
}

int Get(char * str)//��str��¼�ķ��ţ��ֱ���ӵ������У�����ó���ǰ���е�ֵ
{
	int begin;//����ȡƬ�εĿ�ʼλ��
	int count = 0;
	int i;
	char op;//��¼�����

	begin = -1;
	op = -1;
	for (i = 0; i < 8;)
	{
		while (i < 8 && str[i] == ' ')
			++i;
		if (i >= 8)
			break;

		if (begin == -1)
			count = No_next(0, i);
		else
		{
			if (op == '+')
				count += No_next(begin, i);
			else if (op == '-')
				count -= No_next(begin, i);
			else
				return -1;
		}

		begin = i + 1;
		op = str[i];

		++i;

	}
	if (begin == -1 || op == -1)
		return 123456789;

	if (op == '+')
		count += No_next(begin, 8);
	else if (op == '-')
		count -= No_next(begin, 8);
	else
		return -1;
	return count;
}

void print(char * p)
{
	int i;
	printf("%d", num[0]);
	for (i = 1; i < 9; i++)
	{
		if (p[i - 1] != ' ')
			printf("%c", p[i - 1]);
		printf("%d", num[i]);
	}
	printf("=100\n");
}

int main()
{
	char str[8];

	for (int i = 0; i < N; i++)
	{
		int x = i;
		for (int j = 0; j < 8; j++)
		{
			str[j] = symbol[x % 3];
			x = x / 3;
		}

		if (Get(str) == 100)
			print(str);
	}
	return 0;
}