#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int w, h;
	while (cin >> w >> h)
	{
		vector<vector<int>> vv;
		vv.resize(w);
		for (auto & i : vv)
		{
			i.resize(h, 1);
		}
		//将方格里面的所有值都初始化成1
		//接下来遍历每个是1的位置，并且将不能走的位置置为0
		int sum = 0;
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				if (vv[i][j] == 1)
				{
					sum++;
					if (i + 2 < w)
						vv[i + 2][j] = 0;
					if (j + 2 < h)
						vv[i][j + 2] = 0;
				}

			}
		}
		cout << sum << endl;
	}
	return 0;
}