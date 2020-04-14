#include <iostream>
#include <string>
using namespace std;

int main1()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0;
		string tmp;
		for (int i = 0; i < str.size(); i++)
		{
			if (count == 0 && str[i] >= 'a' && str[i] <= 'z')
			{
				tmp.push_back(str[i]);
			}
			else if (count && str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 32;
				tmp.push_back(str[i]);
				count--;
			}
			else if (str[i] == '_')
			{
				count++;
			}
		}
		cout << tmp << endl;
	}
	return 0;
}