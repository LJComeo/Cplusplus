#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* 返回两次操作后，数组元素之和的最小值
	* @param nums int整型vector 这你你需要操作的数组
	* @return long长整型
	*/
	long long minimumValueAfterDispel(vector<int>& nums) {
		int n = nums.size();
		long long count = 0;
		sort(nums.begin(), nums.end());
		int tmp = n / 2;
		int cur = nums[tmp];
		int pos = 0;
		for (int i = 0; i < n; i++)
		{
			
		}
		sort(nums.begin(), nums.end());
		cur = nums[tmp];
		for (int i = 0; i < n; i++)
		{
			if (nums[i] >= cur)
			{
				nums[i] -= cur;
			}
			count += nums[i];
		}
		return count;
	}
};

int main()
{
	Solution s;
	vector<int> v{ 9, 1, 2, 7, 2, 1, 6, 0, 1, 8 };
	cout << s.minimumValueAfterDispel(v) << endl;

	return 0;
}