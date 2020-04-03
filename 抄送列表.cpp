#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s1;
	string s2;
	while (getline(cin,s1))
	{
		getline(cin, s2);
		vector<string> vs;
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] == '\"')
			{
				vs.push_back(s1.substr(i + 1, s1.find('\"', i + 1) - i - 1));
				i = s1.find('\"', i + 1) + 1;
			}
			else
			{
				if (s1.find(',', i) == s1.npos)//如果后序不存在逗号就进这个判断
				{
					vs.push_back(s1.substr(i, s1.size() - i));
					i = s1.size();
				}
				else
				{
					vs.push_back(s1.substr(i, s1.find(',', i) - i));
					i = s1.find(',', i);
				}
			}
		}
		cout << ((find(vs.begin(), vs.end(), s2) != vs.end()) ? "Ignore" : "Important!") << endl;
	}
	return 0;
}