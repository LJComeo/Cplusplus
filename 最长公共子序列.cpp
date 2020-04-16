#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int CalNum(string &str1, string &str2, int m, int n)
{
	vector<vector<int>> vmap(m + 1, vector<int>(n + 1));
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			if (i == 0 || j == 0)
				vmap[i][j] = 0;
			else if (str1[i - 1] == str2[j - 1])
				vmap[i][j] = vmap[i - 1][j - 1] + 1;
			else
				vmap[i][j] = max(vmap[i - 1][j], vmap[i][j - 1]);
		}
	}
	return vmap[m][n];
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << CalNum(str1, str2, str1.size(), str2.size()) << endl;
	}
	return 0;
}