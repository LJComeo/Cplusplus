#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
	int FirstNotRepeatingChar(string str)
	{
		if (str.empty())
			return -1;
		char buffer[256] = { 0 };
		for (int i = 0; i < str.size(); i++)
		{
			buffer[str[i]]++;
		}
		for (int i = 0; i < str.size(); i++)
		{
			if (buffer[str[i]] == 1)
				return i;
		}
	}
};