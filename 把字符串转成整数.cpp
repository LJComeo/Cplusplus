#include <iostream>
using namespace std;

class Solution {
public:
	int StrToInt(string str)
	{
		bool flag = true;
		int sum = 0;
		if (str.empty())
			return 0;
		int i = 0;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				flag = false;
			i++;
		}
		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		{
			if (flag && (sum > INT_MAX / 10 || ((sum == INT_MAX / 10) && INT_MAX % 10 < (str[i] - '0'))))
			{
				return 0;
			}
			else if (!flag && (sum < INT_MIN / 10 || ((sum == INT_MIN / 10) && INT_MIN % 10 >('0' - str[i]))))
			{
				return 0;
			}
			else
			{
				if (flag)
				{
					sum = sum * 10 + (str[i] - '0');
				}
				else
				{
					sum = sum * 10 - (str[i] - '0');
				}
				i++;
			}
		}
		return sum;
	}
};

int main()
{
	string str = "-2147483649";
	Solution s;
	int tmp = s.StrToInt(str);
	cout << tmp << endl;


	return 0;
}