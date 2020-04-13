#include <iostream>
#include <string>
#include <set>
using namespace std;

int main1()
{
	int n;
	string res = "22233344455566677778889999";
	string s;
	while (cin >> n)
	{
		set<string> ss;
		int count;
		while (n--)
		{
			count = 0;
			cin >> s;
			string tmp;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] >= 'A' && s[i] <= 'Z')
				{
					tmp += res[s[i] - 'A'];
					count++;
					if (count == 3)
						tmp += '-';
				}
				else if (s[i] >= '0' && s[i] <= '9')
				{
					tmp += s[i];
					count++;
					if (count == 3)
						tmp += '-';
				}
			}
			ss.insert(tmp);
		}
		for (auto & i : ss)
		{
			cout << i << endl;
		}
		cout << endl;
	}
	return 0;
}