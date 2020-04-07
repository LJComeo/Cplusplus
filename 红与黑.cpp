#include <iostream>
#include <vector>
using namespace std;

int count = 0;
//void Result(vector<vector<char>> &vvc, int x, int y)
//{
//	if (x < 0 || x >= vvc.size() || y < 0 || y >= vvc[0].size() || vvc[x][y] == '#')//超出界限，或者碰到红色就跳出
//		return;
//	count++;
//	vvc[x][y] = '#';
//	Result(vvc, x - 1, y);
//	Result(vvc, x + 1, y);
//	Result(vvc, x, y - 1);
//	Result(vvc, x, y + 1);
//}

int main1()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<char>> vtmp(m, vector<char>(n));
		int x = 0, y = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> vtmp[i][j];
				if (vtmp[i][j] == '@')//找到初始的位置
				{
					x = i;
					y = j;
				}
			}
		}
		//Result(vtmp, x, y);
		//cout << count << endl;
		//count = 0;
	}
	return 0;
}