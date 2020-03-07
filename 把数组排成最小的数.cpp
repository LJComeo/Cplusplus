#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
	set<string> ss;
	string s;
	string tmp;

	string PrintMinNumber(vector<int> numbers)
	{
		if (numbers.empty())
			return s;
		Arranged(numbers, 0, numbers.size());
		for (auto &i : ss)
		{
			s = i;
			break;
		}
		return s;
	}
	bool Arranged(vector<int> numbers, int n, int end)
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			tmp += to_string(numbers[i]);
			
		}
		ss.insert(tmp);
		tmp.clear();

		for (int i = n; i < end; i++)
		{
			swap(numbers[i],numbers[n]);
			if (Arranged(numbers, n + 1, end))
			{
				return true;
			}
			swap(numbers[n], numbers[i]);
		}
		return false;
	}


	
};

int main1()
{
	vector<int>  v{ 3, 5, 1, 4, 2 };
	Solution s;
	string ret = s.PrintMinNumber(v);
	cout << ret << endl;
	return 0;
}