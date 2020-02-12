#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main2()
{
	int n;
	while (cin >> n)
	{
		int m;
		vector<int> v;
		for (int i = 0; i < n; i++)
		{
			cin >> m;
			v.push_back(m);
		}
		if (v.empty())
		{
			return -1;
		}
		int sum = v[0];
		int max = v[0];
		for (int i = 0; i < v.size(); i++)
		{
			sum = (sum > 0) ? sum + v[i] : v[i];
			max = (sum < max) ? max : sum;
		}
		cout <<  max;
	}
	return 0;
}