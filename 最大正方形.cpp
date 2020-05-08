#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
以dp[i][j]为正方形的右下角，这个时候的dp[i][j]的值为以它为右下角的正方形的最大边长
这个位置等于左上、上、左三个方向的最小值+1
dp[i][j] = min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;
*/

class Solution
{
public:
	int maximalSquare(vector<vector<char>>& matrix)
	{
		if (matrix.size() == 0 || matrix[0].size() == 0)
		{
			return 0;
		}
		int Max = 0;
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] == '1')
				{
					if (i == 0 || j == 0)
						dp[i][j] = 1;
					else
						dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + 1;
				}
				Max = max(Max, dp[i][j]);
			}
		}
		int S = Max * Max;
		return S;
	}
};


int main()
{


	return 0;
}