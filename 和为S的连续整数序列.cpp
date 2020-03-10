#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum)
	{
		vector<vector<int>> vret;
		int left = 1, right = 1, sumtmp = 1;
		while (left <= right)
		{
			right++;
			sumtmp += right;
			while (sumtmp > sum)
			{
				sumtmp -= left;
				left++;
			}
			if (sumtmp == sum && left != right)
			{
				vector<int> tmp;
				for (int i = left; i <= right; i++)
				{
					tmp.push_back(i);
				}
				vret.push_back(tmp);
			}
		}
		return vret;
	}
};

int main()
{



	return 0;
}