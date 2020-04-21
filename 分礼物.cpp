#include <iostream>
using namespace std;

int main1()
{
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int count = 0;
	if (n < m)
	{
		if (m % n == 0)
			count = 0;
		else
		{
			int cur = m % n;
			if (a < b)
			{
				count = cur * a;
			}
			else if (a > b)
			{
				count = cur * b;
			}
			else
			{
				count = cur * a;
			}
		}
	}
	else
	{
		if (n - m == 0)
		{
			count = 0;
		}
		else
		{
			int tmp = n - m;
			/*int flag = n % m;*/
			if (a < b)
			{
				count = tmp * a;
			}
			else if (a > b)
			{
				count = tmp * b;
			}
			else
			{
				count = tmp * a;
			}
		}
	}
	cout << count << endl;
	return 0;
}