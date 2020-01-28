#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits)
	{
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits[i] == 9)
			{
				digits[i] = 0;
			}
			else
			{
				digits[i]++;
				return digits;
			}
		}

		digits.push_back(0);
		digits[0] = 1;
		return digits;
	}
};

int main1()
{
	Solution s;
	vector<int> v = { 1, 2, 3 };
	vector<int> vi = s.plusOne(v);
	for (auto &i : vi)
	{
		cout << i << ' ';
	}


	return 0;
}