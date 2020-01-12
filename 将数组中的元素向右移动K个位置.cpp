#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	void rotate(vector<int> nums, int k)
	{
		queue<int> qu;
		int length = nums.size();
		for (int i = length - 1; i >= 0; i--)
		{
			qu.push(nums[i]);
		}
		while (k)
		{
			int tmp = qu.front();
			qu.pop();
			qu.push(tmp);
			k--;
		}
		for (int i = length - 1; i >= 0; i--)
		{
			nums[i] = qu.front();
			qu.pop();
		}
	}
};