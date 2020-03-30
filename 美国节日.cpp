#include <iostream>
#include <vector>
using namespace std;

int week(int year, int month, int day)//������һ�������ڼ�
{
	if (month == 1 || month == 2)
	{
		month += 12;
		year -= 1;
	}//���չ�ʽ��1��2�·ݱ��뵱����һ���13,14�¼���

	int century = year / 100;
	year %= 100;
	int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day - 1;
	week = (week % 7 + 7) % 7;

	if (week == 0)
	{
		week = 7;
	}
	return week;
}

int day(int year, int month, int count, int weektmp)//�ҵ��涨�����µĵڼ������ڼ�
{
	int w = week(year, month, 1);//������µĵ�һ��һ�������ڼ�
	int day1 = 1 + (count - 1) * 7 + (7 + weektmp - w) % 7;//(7 + weektmp - w) % 7������:�ȼӵ���һ��w��Ȼ���ȥw���͵������죬Ȼ�������Ҫ�ܼ��ͼ����ܼ�������
	return day1;
}

void Day1(int year)
{
	cout << year << "-01-01" << endl;
}

void Day2(int year)
{
	cout << year << "-01-" << day(year, 1, 3, 1) << endl;
}

void Day3(int year)
{
	cout << year << "-02-" << day(year, 2, 3, 1) << endl;
}

void Day4(int year)
{
	int w = week(year, 6, 1);
	int d = 31 - ((w == 1) ? 6 : (w - 2));
	cout << year << "-05-" << d << endl;
}

void Day5(int year)
{
	cout << year << "-07-04" << endl;
}

void Day6(int year)
{
	int d = day(year, 9, 1, 1);
	if (d < 10)
		cout << year << "-09-0" << day(year, 9, 1, 1) << endl;
	else
		cout << year << "-09-" << day(year, 9, 1, 1) << endl;
}

void Day7(int year)
{
	cout << year << "-11-" << day(year, 11, 4, 4) << endl;
}

void Day8(int year)
{
	cout << year << "-12-25" << endl;
}

void test(int year)
{
	Day1(year);
	Day2(year);
	Day3(year);
	Day4(year);
	Day5(year);
	Day6(year);
	Day7(year);
	Day8(year);
}


int main1()
{
	int year;
	while (cin >> year)
	{
		test(year);
		putchar('\n');
	}
	return 0;
}


