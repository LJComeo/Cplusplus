#include <iostream>
using namespace std;

//exponent是整数，有可能为正，也可能为负
class Solution {
public:
	double Power(double base, int exponent)
	{
		double tmp = (double)1;
		if (base < 1E-6 && base > -1E-6)
		{
			return 0;
		}
		if (exponent == 0)
		{
			return (double)1;
		}
		if (exponent == 1)
		{
			return base;
		}
		if (exponent > 0)
		{
			while (exponent--)
			{
				tmp *= base;
			}
		}
		else
		{
			int e = -exponent;
			while (e--)
			{
				tmp *= base;
			}
			tmp = 1 / tmp;
		}
		return tmp;
	}
};

int main1()
{
	Solution s;
	cout << s.Power(2.1, 3) << endl;
	return 0;
}