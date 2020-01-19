#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int j = 0, len = name.size();
		for (int i = 0; i < typed.size(); i++)
		{
			if (typed[i] == name[j] && j < len)
			{
				j++;
				continue;
			}
			else if (j > 0 && typed[i] == name[j - 1]) //首字母不同时j-1超出索引范围
			{
				continue;
			}
			else
			{
				return false;
			}
		}
		if (j == len)
			return true;
		else
			return false;
	}
};


int main()
{
	Solution s;
	string name = "alex";
	string typed = "aaleex";
	cout << s.isLongPressedName(name, typed) << endl;


	return 0;
}