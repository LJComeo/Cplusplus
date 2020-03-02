#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	set<string> ss;
	bool flag = false;
	vector<string> vs;
	bool entance(string str, int start, int end)
	{
		if (flag)
		{
			ss.insert(str);
		}
		flag = true;
		int i;
		for (i = start; i < end; i++)
		{
			swap(str[i], str[start]);
			if (entance(str, start + 1, end))
				return true;
			swap(str[start], str[i]);
		}
		return false;
	}
	vector<string> Permutation(string str)
	{
		if (str.empty())
			return vs;
		int n = str.size();
		entance(str, 0, n);
		for (auto &i : ss)
		{
			vs.push_back(i);
		}
		return vs;
	}
};


int main()
{


	return 0;
}
