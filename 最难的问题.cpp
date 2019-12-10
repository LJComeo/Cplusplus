#include <iostream>
#include <string>
using namespace std;

int main1()
{
	string s;
	while (getline(cin,s))
	{
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			if (s[i] >= 'A' && s[i] <= 'Z')
			{
				if (s[i] < 'F')
				{
					s[i] = 'V' + (s[i] - 'A');
				}
				else
				{
					s[i] = s[i] - 5;
				}
			}
		}
		cout << s << endl;
	}
	
	return 0;
}