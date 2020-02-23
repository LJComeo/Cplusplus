#include <iostream>
#include <vector>
using namespace std;

/*
˳ʱ���ӡ����ʹ�õķ�������һȦһȦ�Ĵ�ӡ�����ھ���һ����n*n�ģ�������һȦ�Ľ��������ֿ���
ֻҪ�������ֿ���ȫ������������ˣ���һ�֣�ֻ��һ�У����������ұߴ�ʱ��top = down��
�ڶ��֣�ֻ��һ�У�������down֮���λ���ǣ�left����rightҲ����ˣ�ֻ��һ������������ټ����ж�top��ʱҲ���ܵ���down
�����֣��������У������Ѿ��������ڶ��еĿ�ͷλ�ã���һ�����Ǳ������µ��ϣ����Ǵ�ʱ��down = top + 1��ֻ��һ�е�ʱ����ߵ�ȻҲ���ܵ����ұߣ�
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