#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		if (array.empty())
			return -1;
		int sum = array[0];
		int max = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			sum = (sum > 0) ? sum + array[i] : array[i];
			max = (sum < max) ? max : sum;
		}
		return max;
	}
};

int main()
{
	Solution s;
	vector<int> v{ -30, 2, 5, 100, -200, 250 };
	int ret = s.FindGreatestSumOfSubArray(v);
	cout << ret << endl;


	return 0;
}