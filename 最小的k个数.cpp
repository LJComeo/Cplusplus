#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
	{
		vector<int> vret;
		int n = input.size();
		if (k > n)
			return vret;
		sort(input.begin(), input.end());
		for (int i = 0; i < k; i++)
		{
			vret.push_back(input[i]);
		}
		return vret;
	}
};


int main1()
{
	Solution s;
	vector<int> v{ 4, 6, 23, 2, 1, 5, 9, 7, 5 };
	vector<int> tmp = s.GetLeastNumbers_Solution(v,5);
	for (auto &i : tmp)
	{
		cout << i << ' ';
	}
	cout << endl;

	return 0;
}