#include <iostream>
using namespace std;

class Solution {
	int calNum(int n)
	{
		int ret = 0;
		while (n)
		{
			ret += (n % 10) * (n % 10);
			n /= 10;
		}
		return ret;
	}
public:
	bool isHappy(int n)
	{
		int low = n, fast = n;
		do
		{
			low = calNum(low);
			fast = calNum(fast);
			fast = calNum(fast);
		}while(low != fast);
		return low == 1;
	}
};

int main()
{
	Solution s;
	cout << s.isHappy(2) << endl;

	return 0;
}