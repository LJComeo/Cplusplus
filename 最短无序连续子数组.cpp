#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums)
	{
		int left = 0, right = 0;
		vector<int> v1;
		for (int i = 0; i < nums.size(); i++)
		{
			v1.push_back(nums[i]);
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != v1[i])
			{
				left = i;
				break;
			}
		}
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (nums[i] != v1[i])
			{
				right = i;
				break;
			}
		}
		if (left == 0 || right == 0)
		{
			return 0;
		}
		return right - left + 1;
	}
};

int main()
{



	return 0;
}