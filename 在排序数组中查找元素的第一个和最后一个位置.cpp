#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> v;
		int start = -1, end = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (start == -1 && nums[i] == target)
			{
				start = i;
			}
			if (nums[i] == target)
			{
				end = i;
			}
		}
		v.emplace_back(start);
		v.emplace_back(end);
		return v;
	}
};


int main()
{



	return 0;
}