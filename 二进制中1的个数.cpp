#include <iostream>
using namespace std;

class Solution {
public:
	int  NumberOf1(int n)
	{
		int count = 0;
		for (int i = 0; i < 32; i++)
		{
			if ((1 << i) & n)
			{
				count++;
			}
		}
		return count;
	}
};