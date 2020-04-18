#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> GetMinNum(vector<int> v, int n)
{
	vector<int> vtmp(v.begin(), v.end());
	vector<int> vret;
	sort(vtmp.begin(), vtmp.end());
	for (int i = 0; i < n; i++)
	{
		vret.push_back(vtmp[i]);
	}
	return vret;
}

int main1()
{
	int n, m, a_i, Q, q;
	cin >> n >> m;//n为持仓数量，m为每天最多卖出的股票数量
	vector<int> v_i;
	vector<int> v_q;
	vector<int> v_data;
	for (int i = 0; i < n; i++)
	{
		cin >> a_i;
		v_i.push_back(a_i);
	}
	cin >> Q;//询问的数量
	int money = 0;
	int day = 1;
	for (int i = 0; i < Q; i++)
	{
		cin >> q;
		v_q.push_back(q);
	}
	for (int i = 0; i < v_q.size(); i++)
	{
		v_data = GetMinNum(v_i, v_q[i]);
		int a = v_q[i] / m;
		int j = v_data.size() - 1;
		int b = v_data.size() - 1;
		while (a)
		{
			for (; j > b - m; j--)
			{
				money += day * v_data[j];
			}
			a--;
			day++;
			b -= m;
		}
		for (; j >= 0; j--)
		{
			money += day * v_data[j];
		}
		cout << money << endl;
		money = 0;
		day = 1;
	}
	return 0;
}