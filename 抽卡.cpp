#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m, k;
	int count = 0;
	int num = 0;
	cin >> n;
	vector<int> Money;
	vector<int> ExCard;
	vector<int> vi;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> k;
		Money.push_back(m);
		ExCard.push_back(k);
	}
	for (int i = 0; i < n; i++)
	{
		if (!num && ExCard[i])
		{
			num += ExCard[i];
			count += Money[i];
		}
		else if (num && ExCard[i])
		{
			num += ExCard[i];
			num--;
			count += Money[i];
		}
		else
		{
			vi.push_back(Money[i]);
		}
	}
	sort(vi.begin(), vi.end());
	int e = vi.size() - 1;
	while (num--)
	{
		count += vi[e];
		e--;
	}
	cout << count << endl;
	return 0;
}