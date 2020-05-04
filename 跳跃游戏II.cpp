#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
	int jump(vector<int>& nums)
	{
		int maxPos = 0, n = nums.size(), end = 0, step = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			if (i <= maxPos)
			{
				maxPos = max(maxPos, i + nums[i]);//不断的寻找最远到达的位置
				if (i == end)//当此时当前的位置遍历到边界时，相当于找到了跳一步的方法，更新边界
				{
					end = maxPos;
					++step;
				}
			}
		}
		return step;
	}
};


int main()
{
	vector<int> v{ 2, 3, 1, 1, 4 };
	Solution s;
	cout << s.jump(v) << endl;

	return 0;
}