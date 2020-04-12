#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int res = INT_MAX;
vector<vector<int>> v(10, vector<int>(10, 0));
void CalNum(vector<vector<char>> &vs, int sx, int sy, int tx, int ty, int tmp)
{
	if (sx < 0 || sy < 0 || v[sx][sy] || sx >= 10 || sy >= 10)
		return;
	if (vs[sx][sy] == '#')
		return;
	if (tmp > res) 
		return;
	if (sx == tx && sy == ty)
	{
		if (tmp < res)
			res = tmp;
		return;
	}
	v[sx][sy] = 1;
	CalNum(vs, sx - 1, sy, tx, ty, tmp + 1);
	CalNum(vs, sx, sy - 1, tx, ty, tmp + 1);
	CalNum(vs, sx + 1, sy, tx, ty, tmp + 1);
	CalNum(vs, sx, sy + 1, tx, ty, tmp + 1);
	v[sx][sy] = 0;
}

int main()
{
	string s;
	while (cin >> s)
	{
		res = INT_MAX;
		vector<vector<char>>vs(10, vector<char>(10));
		for (int i = 0; i<10; i++)
		{
			for (int j = 0; j<10; j++)
			{
				if (i == 0)
					vs[i][j] = s[j];
				else
					cin >> vs[i][j];
			}
		}
		CalNum(vs, 0, 1, 9, 8, 0);
		cout << res << endl;
	}
	return 0;
}