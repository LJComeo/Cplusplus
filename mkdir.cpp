#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	ios::sync_with_stdio(false);//数据不进入缓冲区
	cin.tie(0);//不刷新缓冲区
	while (cin >> n)
	{
		vector<bool> vb(n, true);
		vector<string> tmp(n);
		for (int i = 0; i < n; i++)
		{
			cin >> tmp[i];
		}
		sort(tmp.begin(), tmp.end());

		for (int i = 0; i < tmp.size() - 1; i++)
		{
			if (tmp[i] == tmp[i + 1])
			{
				vb[i] = false;
			}
			else if (tmp[i].size() < tmp[i + 1].size() && tmp[i] == tmp[i + 1].substr(0, tmp[i].size())
				&& tmp[i + 1][tmp[i].size()] == '/')
			{
				vb[i] = false;
			}
		}
		for (int i = 0; i < tmp.size(); i++)
		{
			if (vb[i] == true)
				cout << "mkdir -p " << tmp[i] << endl;
		}
		cout << endl;
	}
	return 0;
}