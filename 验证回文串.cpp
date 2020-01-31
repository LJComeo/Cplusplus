#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s)
	{
		string s1;
		if (!s.empty())
		{
			for (int i = 0; i < s.size(); i++)
			{
				if (isalnum(s[i]))
				{
					if (isalpha(s[i]))
					{
						s[i] = tolower(s[i]);
						s1.push_back(s[i]);
					}
					s1.push_back(s[i]);
				}
			}
			int n = s1.size();
			if (n == 1)
			{
				return true;
			}
			for (int i = 0; i < n; i++)
			{
				if (s1[i] != s1[n - 1 - i])
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main2()
{
	Solution s;
	string s1 = "0P";
	cout << s.isPalindrome(s1);

	return 0;
}