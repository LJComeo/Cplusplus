#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int pivotIndex(vector<int>& nums)
	{
		int n = nums.size();
		if (0 == n)
		{
			return -1;
		}
		int left = 0;
		int right = accumulate(nums.begin(), nums.end(), 0) - nums[0];
		if (left == right)
		{
			return 0;
		}
		for (int i = 1; i<n; i++)
		{
			left += nums[i - 1];
			right -= nums[i];
			if (left == right)
			{
				return i;
			}
		}
		return -1;
	}
};


int main()
{
	Solution s;
	vector<int> v = { 1, 7, 3, 6, 5, 6 };
	int tmp = s.pivotIndex(v);


	return 0;
}