#include <iostream>
#include <vector>
#include <map>
using namespace std;

int GetResult(int timeno, vector<int> &v)
{
	int count = 0;
	map<int, int> m;
	for (int i = 0; i < v.size(); i += 2)
	{
		m.insert(pair<int, int>(v[i], v[i + 1]));
	}
	int tmp = 0;
	for (int i = 0; i < timeno; i++)
	{
		if (m[i])
		{
			count += m[i];
			tmp = m[i];
		}
		else
		{
			count += tmp;
		}
	}
	return count;
}


int main1()
{
	int n;
	while (cin >> n)
	{
		int mi, a, b;
		vector<vector<int>> vvm;
		for (int i = 0; i < n; i++)
		{
			cin >> mi;
			vector<int> vm;
			for (int i = 0; i < mi; i++)
			{
				cin >> a >> b;
				vm.push_back(a);
				vm.push_back(b);
			}
			vvm.push_back(vm);
		}
		int Q, qi;
		vector<int> vqi;
		cin >> Q;
		for (int i = 0; i < Q; i++)
		{
			cin >> qi;
			vqi.push_back(qi);//所有对赛制的猜测
		}
		
		for (int i = 0; i < vqi.size(); i++)///针对每一种赛制
		{
			int tmp = 0;
			int t = 0;
			int cur = 0;
			for (int j = 0; j < vvm.size(); j++)//针对每一个乌龟的参数
			{
				tmp = GetResult(vqi[i], vvm[j]) > tmp ? GetResult(vqi[i], vvm[j]) : tmp;
				if (tmp > t)
					cur = j;
				t = tmp;

			}
			cur++;
			cout << cur << endl;
			cur = 0;
		}

	}

	return 0;
}