#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int> > res(1);//先将空集放到集合里面
		for (int i = 0; i < nums.size(); i++)//遍历nums中的元素
		{
			int n = res.size();//每次求出res的大小，是因为要将下一个元素给他们每个元素的后面加
			for (int j = 0; j < n; j++)//遍历现在res中的元素
			{
				vector<int> tmp = res[j];//让中间的数组先等于每个res中的元素，方便加入新的
				tmp.push_back(nums[i]);//加入新的元素
				res.push_back(tmp);//将加入结束后的数组tmp，又放回res中
			}
		}
		return res;//最后返回res
	}
};

int main1()
{
	Solution s;
	vector<int> v = { 1, 2, 3 };
	vector<vector<int>>vt = s.subsets(v);
	for (auto &i : vt)
	{
		for (auto &j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}


	return 0;
}