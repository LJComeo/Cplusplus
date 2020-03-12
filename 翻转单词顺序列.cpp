#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str)
	{
		if (str.empty())
			return str;
		if (str.rfind(" ") == -1)
			return str;
		reverse(str.begin(), str.end());
		int start = 0;
		int end = str.find(" ", start);
		while (end != -1)
		{
			reverse(str.begin() + start, str.begin() + end);
			start = end + 1;
			end = str.find(" ", start);
		}
		reverse(str.begin() + start, str.end());
		return str;
	}
};

int main1()
{
	string s = "Hello World!";
	Solution s1;
	string tmp = s1.ReverseSentence(s);
	cout << tmp << endl;

	return 0;
}