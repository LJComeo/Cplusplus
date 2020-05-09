#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int mySqrt(int x)
	{
		if (x == 0)
			return 0;
		return sqrt(x);
	}
};


int main()
{
	Solution s;
	cout << s.mySqrt(8) << endl;

	return 0;
}