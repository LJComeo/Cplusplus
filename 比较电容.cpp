#include <iostream>
#include <vector>
using namespace std;

bool IsGreater(vector<int> & vb,vector<int> &vl,int n, int m)
{
	for (int i = 0; i < vb.size(); i++)
	{
		if (vb[i] == n && vl[i] == m)
			return true;
	}
	for (int i = 0; i < vb.size(); i++)
	{
		if (vb[i] == n)
		{
			return IsGreater(vb, vl, vl[i], m);
		}
		else if (vl[i] == m)
		{
			return IsGreater(vb, vl, n, vb[i]);
		}
	}
	return false;
}

bool IsLess(vector<int> & vb, vector<int> &vl, int n, int m)
{
	for (int i = 0; i < vb.size(); i++)
	{
		if (vb[i] == m && vl[i] == n)
			return true;
	}
	for (int i = 0; i < vb.size(); i++)
	{
		if (vb[i] == m)
		{
			return IsLess(vb, vl, n, vl[i]);
		}
		else if (vl[i] == n)
		{
			return IsLess(vb, vl, vb[i], m);
		}
	}
	return false;
}

int main2()
{
	int n, a, b;
	int num1, num2;
	vector<int> better;
	vector<int> less;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		better.push_back(a);
		less.push_back(b);
	}
	cin >> num1 >> num2;
	bool tmp = IsGreater(better, less, num1, num2);
	bool cur = IsLess(better, less, num1, num2);
	if (tmp == true && cur == false)
		cout << 1 << endl;
	else if (tmp == false && cur == true)
		cout << -1 << endl;
	else
		cout << 0 << endl;

	return 0;
}


/*

4

1  2

2  4

1  3

4  3

2  3

*/