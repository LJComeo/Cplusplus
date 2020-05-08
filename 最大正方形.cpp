#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
��dp[i][j]Ϊ�����ε����½ǣ����ʱ���dp[i][j]��ֵΪ����Ϊ���½ǵ������ε����߳�
���λ�õ������ϡ��ϡ��������������Сֵ+1
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