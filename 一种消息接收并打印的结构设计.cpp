#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main1()
{
	int n;
	int m;
	map<int, int> mp;
	while (cin >> n)
	{
		int tmp = 1;
		vector<int> v(n + 1,0);
		while (n--)
		{
			cin >> m;
			v.push_back(m);
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (mp[tmp])
			{
				tmp++;
				i--;
				continue;
			}
			if (v[i] > tmp )
			{
				mp[v[i]] = tmp;
			}
			else if (v[i] == tmp)
			{
				mp[v[i]] = tmp;
				tmp++;
			}
		}
		for (int i = 0; i < mp.size();i++)
		{
			if (i == mp[i])
				continue;
			else
				mp[i] = mp[i - 1];
		}
		mp.erase(0);
		for (auto & i : mp)
		{
			cout << i.first << ' ' << i.second << endl;
		}

		
	}
	return 0;
}