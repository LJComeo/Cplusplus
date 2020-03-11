#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n)
	{
		string s;
		if (str.empty())
			return s;
		if (n == 0)
			return str;
		queue<char> qc;
		for (int i = 0; i < str.size(); i++)
		{
			qc.push(str[i]);
		}
		for (int i = n; i < str.size(); i++)
		{
			s.push_back(str[i]);
		}
		for (int i = 0; i < n; i++)
		{
			int tmp = qc.front();
			qc.pop();
			s.push_back(tmp);
		}
		return s;
	}
};

int main()
{
	string s = "dakdjadk";
	Solution s1;
	string ret = s1.LeftRotateString(s, 3);
	cout << ret << endl;

	return 0;
}