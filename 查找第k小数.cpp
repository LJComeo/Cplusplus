#include <iostream>
#include <set>
using namespace std;

int main2()
{
	int n, num, k;
	while (cin >> n)
	{
		set<int> s;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			s.insert(num);
		}
		cin >> k;
		int count = 0;
		for (auto & i : s)
		{
			count++;
			if (count == k)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}