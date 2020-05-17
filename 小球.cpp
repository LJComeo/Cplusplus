#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int q;

	while (cin >> q)
	{
		for (int i = 0; i < q; ++i)
		{
			int n, m;
			cin >> n >> m;
			int x, y, w, t, cnt = 0;
			cin >> x >> y >> w >> t;
			int offset1, offset2;
			--x, --y;
			if (w == 0)
			{
				offset1 = -1;
				offset2 = -1;
			}
			else if (w == 1)
			{
				offset1 = -1;
				offset2 = 1;
			}
			else if (w == 2)
			{
				offset1 = 1;
				offset2 = 1;
			}
			else
			{
				offset1 = 1;
				offset2 = -1;
			}
			for (int j = 0; j < t; ++j)
			{
				x += offset1;
				y += offset2;
				if (x - 1 == 0 || x + 1 == n - 1)
				{
					++cnt;
					offset1 *= -1;
				}
				if (y - 1 == 0 || y + 1 == m - 1)
				{
					++cnt;
					offset2 *= -1;
				}
			}
			cout << cnt << endl;
		}
	}

	return 0;
}