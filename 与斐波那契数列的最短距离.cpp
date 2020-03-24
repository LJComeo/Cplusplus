#include <iostream>
#include <algorithm>
using namespace std;

int main1()
{
	int n;
	while (cin >> n)
	{
		int m = 0, m_1 = 1, m_2 = 0;
		int l = 0, s = 0;
		while (1)
		{
			m = m_1 + m_2;
			m_2 = m_1;
			m_1 = m;
			if (m < n)
			{
				l = n - m;
			}
			else
			{
				s = m - n;
				break;
			}
		}
		int ret = min(l, s);
		cout << ret << endl;
	}
	return 0;
}