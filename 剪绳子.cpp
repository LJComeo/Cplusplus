#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int cutRope(int number)
	{
		if (number <= 1)
			return 0;
		if (number == 2)
			return 1;
		if (number == 3)
			return 2;
		vector<int> v(number + 1);
		//当数字为1,2,3时，这个值是确定的，只有数字为4及4以上，才可能发生变化，然后直接暴力算就可以了
		v[1] = 1;
		v[2] = 2;
		v[3] = 3;
		int Max = 0;
		for (int i = 4; i <= number; i++)
		{
			for (int j = 1; j <= i / 2; j++)
			{
				Max = max(Max, v[j] * v[i - j]);
			}
			v[i] = Max;
		}
		return v[number];
	}
};