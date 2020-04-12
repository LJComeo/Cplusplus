#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main1()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				cout << str[i];
			}
		}
		cout << endl;
	}
	return 0;
}