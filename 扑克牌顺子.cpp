#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool IsContinuous(vector<int> numbers)
	{
		if (numbers.size() != 5)
			return false;
		vector<int> v;
		set<int> s;
		int sum = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == 0)
				sum++;
			else
			{
				s.insert(numbers[i]);
			}
		}
		if (sum + s.size() != 5)//如果出现重复的数字，就会出现这种情况，因为set会去重
			return false;
		for (auto & i : s)
		{
			v.push_back(i);
		}
		if ((v[v.size() - 1] - v[0]) > 4)
			return false;
		return true;
	}
};

int main2()
{
	vector<int> v{ 3, 1, 2, 4, 6 };
	Solution s;
	cout << s.IsContinuous(v) << endl;


	return 0;
}