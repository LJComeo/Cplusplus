#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s)
	{
		int n = s.size();
		if (!s.empty())
		{
			int num = 0;
			int tmp = s.rfind(' ');
			if (tmp < 0)
			{
				return n;
			}
			else if (tmp == n - 1)
			{
				for (int i = tmp - 1; i >= 0; i--)
				{
					if (s[i] != ' ')
					{
						num++;
					}
					if (s[i] == ' ' && num != 0)
					{
						break;
					}

				}
				return num;
			}
			else
			{
				return n - (tmp + 1);
			}
		}
		return 0;
	}
};

int main1()
{
	Solution s;
	string s1 = "a b  ";
	cout << s.lengthOfLastWord(s1) << endl;


	return 0;
}