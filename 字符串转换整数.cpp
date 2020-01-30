#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int myAtoi(string str) 
	{
		int res = 0;
		int i = 0;
		int flag = 1;
		while (str[i] == ' ') // 1. ���ո�
		{ 
			i++; 
		}	
		if (str[i] == '-')// 2. ������
		{ 
			flag = -1;
		}
		if (str[i] == '+' || str[i] == '-')
		{
			i++;
		}
		while (i < str.size() && isdigit(str[i])) // 3. ��������
		{
			int r = str[i] - '0';
			
			if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) //4. �������
			{
				return flag > 0 ? INT_MAX : INT_MIN;
			}
			res = res * 10 + r;
			i++;
		}
		return flag > 0 ? res : -res;
	}
};

int main2()
{
	Solution s;
	string str = "-666551137192319027401tywiqyi";
	cout << s.myAtoi(str) << endl;

	return 0;
}