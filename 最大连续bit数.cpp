#include <iostream>
#include <algorithm>
using namespace std;

int main2()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int Max = 0;
		while (n)
		{
			while (n & 1)
			{
				count++;
				n >>= 1;
			}
			Max = max(Max, count);
			count = 0;
			n >>= 1;
		}
		cout << Max << endl;
	}

	return 0;
}