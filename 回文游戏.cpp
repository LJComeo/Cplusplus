#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> ss;
bool tag = true;
void AllKindS(string s, int n, int end)
{
	if (tag == false)
	{
		ss.insert(s);
	}
	tag = false;
	int i;
	for (i = n; i < end; i++)
	{
		swap(s[i], s[n]);
		AllKindS(s, n + 1, end);
		swap(s[n], s[i]);
	}
}

bool IsRight(string s)
{
	if (s.size() == 0)
		return false;
	if (s.size() == 1)
		return true;
	string tmp = s;
	reverse(tmp.begin(), tmp.end());
	return tmp == s;
}

int main2()
{
	int t;
	int flag = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string ret;
		string s;
		cin >> s;
		while (s.size() >= 1)
		{
			if (flag % 2 == 0)
			{
				AllKindS(s, 0, s.size());
				for (auto & e : ss)
				{
					if (IsRight(e))
					{
						ret = "Cassidy";
						break;
					}
				}
				if (!ret.empty())
				{
					break;
				}
				s.erase(s.size() - 1);
				flag++;
			}
			else
			{
				AllKindS(s, 0, s.size());
				for (auto & e : ss)
				{
					if (IsRight(e))
					{
						ret = "Eleanore";
						break;
					}
				}
				if (!ret.empty())
				{
					break;
				}
				s.erase(s.size() - 1);
				flag++;
			}
		}
		cout << ret << endl;
		flag = 0;
		ss.clear();
	}
	return 0;
}