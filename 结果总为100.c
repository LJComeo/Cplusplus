#include <stdio.h>

#define N (6561) //三个字符，8个位置的所有可能的数量


int num[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
char symbol[3] = { ' ', '+', '-' };

int No_next(int i, int n)//获取当前数字的大小
{
	int sum = 0;
	for (;i <= n; ++i)
		sum = sum * 10 + num[i];
	return sum;
}

int Get(char * str)//把str记录的符号，分别添加到数组中，计算得出当前排列的值
{
	int begin;//待获取片段的开始位置
	int count = 0;
	int i;
	char op;//记录运算符

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