#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* �������β���������Ԫ��֮�͵���Сֵ
	* @param nums int����vector ��������Ҫ����������
	* @return long������
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