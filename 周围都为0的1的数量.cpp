#include <iostream>
#include <string>
#include <vector>
using namespace std;

void fillZero(vector<string> &data, int x, int y)
{
	if (x >= 0 && x < data.size() && y >= 0 && y < data[0].size() && data[x][y] == '1')
	{
		data[x][y] = '0';
		fillZero(data, x + 1, y);
		fillZero(data, x - 1, y);
		fillZero(data, x, y + 1);
		fillZero(data, x, y - 1);
	}
}

int mainKS4()
{
	char ch;
	int X, Y, cnt;

	while (cin >> X >> Y)
	{
		vector<string> data(X);
		for (int i = 0; i < X; ++i)
		{
			string line;
			for (int j = 0; j < Y; ++j)
			{
				cin >> ch;
				line += ch;
			}
			data[i] = line;
		}
		for (int i = 0; i < X; ++i)
		{
			fillZero(data, i, 0);
			fillZero(data, i, Y - 1);
		}
		for (int i = 0; i < Y; ++i)
		{
			fillZero(data, 0, i);
			fillZero(data, X - 1, i);
		}
		cnt = 0;
		for (int i = 0; i < X; ++i)
		{
			for (int j = 0; j < Y; ++j)
			{
				if (data[i][j] == '1')
				{
					++cnt;
					fillZero(data, i, j);
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}