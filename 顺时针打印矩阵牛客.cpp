#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
		vector<int> v;
		if (m == 0 || n == 0)
		{
			return v;
		}
		int left = 0, right = m - 1, top = 0, down = n - 1;
		while ((left <= right) && (top <= down))
		{
			for (int i = left; i <= right; i++)
			{
				v.push_back(mat[top][i]);
			}
			if (top < down)
			{
				for (int i = top + 1; i <= down; i++)
				{
					v.push_back(mat[i][right]);
				}
			}
			if ((top < down) && (left < right))
			{
				for (int i = right - 1; i >= left; i--)
				{
					v.push_back(mat[down][i]);
				}
			}
			if ((top + 1 < down) && left < right)
			{
				for (int i = down - 1; i >= top + 1; i--)
				{
					v.push_back(mat[i][left]);
				}
			}
			left++, right--, top++, down--;
		}
		return v;
	}
};

int main()
{

	return 0;
}