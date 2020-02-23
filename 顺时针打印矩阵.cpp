#include <iostream>
#include <vector>
using namespace std;

/*
顺时针打印矩阵，使用的方法就是一圈一圈的打印，由于矩阵不一定是n*n的，因此最后一圈的结束有三种可能
只要将这三种可能全部遍历完就行了，第一种：只有一行，即遍历到右边此时的top = down；
第二种：只有一列，遍历到down之后的位置是，left就与right也相等了，只有一个的情况就是再加入判断top此时也不能等于down
第三种：两个多列，但是已经遍历到第二行的开头位置，下一步就是遍历从下到上，但是此时的down = top + 1，只有一列的时候，左边当然也不能等于右边；
*/

class Solution
{
public:
	vector<int> printMatrix(vector<vector<int>> matrix)
	{
		vector<int> v;
		int m = matrix.size();
		int n = matrix[0].size();
		if (m == 0 || n == 0)
		{
			return v;
		}
		int left = 0, right = n - 1, top = 0, down = m - 1;
		while ((left <= right) && (top <= down))
		{
			for (int i = left; i <= right; i++)
			{
				v.push_back(matrix[top][i]);
			}
			if (top < down)
			{
				for (int i = top + 1; i <= down; i++)
				{
					v.push_back(matrix[i][right]);
				}
			}
			if ((top < down) && (left < right))
			{
				for (int i = right - 1; i >= left; i--)
				{
					v.push_back(matrix[down][i]);
				}
			}
			if ((top + 1 < down) && left < right)
			{
				for (int i = down - 1; i >= top + 1; i--)
				{
					v.push_back(matrix[i][left]);
				}
			}
			left++, right--, top++, down--;
		}
		return v;
	}
};

int main1()
{
	Solution s;
	vector<vector<int>> vv{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<int> vtmp = s.printMatrix(vv);
	for (auto &i : vtmp)
	{
		cout << i << ' ';
	}

	return 0;
}