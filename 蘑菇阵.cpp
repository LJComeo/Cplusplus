#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		vector<vector<int>> vb((n + 1), vector<int>(m + 1,0));//蘑菇
		vector<vector<double>> vd((n + 1), vector<double>(m + 1,0));//概率
		int x, y;
		while (k--)
		{
			cin >> x >> y;
			vb[x][y] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1)
				{
					vd[1][1] = 1.0;
					continue;
				}
				if (vb[i][j] == 1)
				{
					vd[i][j] = 0;
					continue;
				}
				if (i == n && j == m)
				{
					vd[i][j] = vd[i - 1][j] + vd[i][j - 1];
					continue;
				}
				//下面判断是四个边界的概率计算
				if (i == n)
				{
					vd[i][j] = vd[i - 1][j] * 0.5 + vd[i][j - 1];
					continue;
				}
				if (i == m)
				{
					vd[i][j] = vd[i - 1][j] + vd[i][j - 1] * 0.5;
					continue;
				}
				if (i == 1)
				{
					vd[i][j] = vd[i][j - 1] * 0.5;
					continue;
				}
				if (j == 1)
				{
					vd[i][j] = vd[i - 1][j] * 0.5;
					continue;
				}
				vd[i][j] = vd[i - 1][j] * 0.5 + vd[i][j - 1] * 0.5;
			}
		}
		printf("%.2lf\n", vd[n][m]);
	}

	return 0;
}