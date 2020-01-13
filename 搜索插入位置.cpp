#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int n = nums.size();
		for (int i = 1; i < n; i++)
		{
			if (nums[i] == target)
			{
				return i;
			}
			if (target > nums[i - 1] && target < nums[i])
			{
				return i;
			}
		}
		if (target == nums[0])
		{
			return 0;
		}
		if (target < nums[0])
		{
			return 0;
		}
		return n;
	}
};

int main()
{


	return 0;
}