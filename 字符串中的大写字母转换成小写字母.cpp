#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
	string toLowerCase(string str)
	{
		for (auto & i : str)
		{
			if (i >= 'A' && i <= 'Z')
			{
				i = 'a' + (i - 'A');
			}
		}
		return str;
	}
};

int main1()
{
	Solution s;
	string str = "adajklsjdDHAKA";
	string tmp = s.toLowerCase(str);
	cout << tmp;
	return 0;
}