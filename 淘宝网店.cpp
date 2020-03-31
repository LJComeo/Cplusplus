#include <iostream>
#include <algorithm>
using namespace std;

bool IsLeap(int year)//判断某年是不是闰年
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return true;
	return false;
}

bool IsPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int DayNum(int year, int month, int day)//计算从一月一日到这个日期的挣钱数
{
	int count = 0;
	for (int i = 1; i < month; i++)
	{
		if (i == 4 || i == 6 || i == 9 || i == 11)
		{
			count += 30;
		}
		else if (IsLeap(year) && i == 2)
		{
			count += 29;
		}
		else if (!IsLeap(year) && i == 2)
		{
			count += 28;
		}
		else
		{
			count += 31;
		}
		if (i == 4 || i == 6 || i == 9)
			count += 30;
		else if (i == 1 || i == 8 || i == 10 || i == 12)
			count += 31;
	}
	if (IsPrime(month))
	{
		count += day;
	}
	else
	{
		count += (2 * day);
	}
	
	return count;
}
int main1()
{
	int count = 0;
	int year1, month1, day1;
	int year2, month2, day2;
	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
	{
		if (year1 < year2)
		{
			if (IsLeap(year1))
				count = 580 - DayNum(year1, month1, day1);
			else
				count = 579 - DayNum(year1, month1, day1);
			for (int i = year1 + 1; i < year2; i++)
			{
				if (IsLeap(i))
					count += 580;
				else
					count += 579;
			}
			count += DayNum(year2, month2, day2);
			if (IsLeap(year1))
				cout << count  + 2<< endl;
			else
				cout << count << endl;
		}
		else
		{
			if (IsPrime(month1))
				cout << DayNum(year2, month2, day2) - DayNum(year1, month1, day1) + 1 << endl;
			else
				cout << DayNum(year2, month2, day2) - DayNum(year1, month1, day1) + 2 << endl;
		}
	}
		
	return 0;
}