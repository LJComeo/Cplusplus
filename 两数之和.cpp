#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> vcur;
		int tmp = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (j != i)
				{
					tmp = nums[i] + nums[j];
					if (tmp == target)
					{
						vcur.push_back(i);
						vcur.push_back(j);
						break;
					}
				}
			}
			if (!vcur.empty())
			{
				break;
			}
		}
		return vcur;
	}
};

int main1()
{


	return 0
}