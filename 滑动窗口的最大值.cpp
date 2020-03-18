#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> vret;
		if (num.empty() || size > num.size())
			return vret;
		int left = 0;
		int right = left + size - 1;
		while (right < num.size())
		{
			vector<int> tmp(num.begin() + left, num.begin() + right + 1);//这个数组中存的就是这段数字，然后找出其中的最大值就行
			sort(tmp.begin(), tmp.end());
			int n = tmp.size();
			vret.push_back(tmp[n - 1]);
			tmp.clear();
			left++;
			right++;
		}
		return vret;
	}
};

int main()
{
	vector<int> v{ 2, 3, 4, 2, 6, 2, 5, 1 };
	Solution s;
	vector<int> vret = s.maxInWindows(v, 3);
	for (auto & i : vret)
	{
		cout << i << ' ';
	}
	cout << endl;

	return 0;
}