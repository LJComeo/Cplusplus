#include <string.h>
#include <iostream>
using namespace std;

int main1()
{
	char id[2], op[11];
	int n, pool, max;

	while (cin >> n)
	{
		pool = max = 0;
		memset(id, 0, sizeof(id));
		memset(op, 0, sizeof(op));
		while (n--)
		{
			cin >> id >> op;
			if (op[0] == 'c' && ++pool>max)
				max = pool;
			if (op[0] == 'd')
				--pool;
		}
		cout << max << endl;
	}
	return 0;
}