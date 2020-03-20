#include <iostream>
using namespace std;

class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool* flag = new bool[rows*cols]();
		for (int i = 0; i < rows*cols; i++)
			flag[i] = false;
		int count = Num(threshold, rows, cols, 0, 0, flag);
		return count;
	}
	int Num(int threshold, int rows, int cols, int x, int y, bool* flag)
	{
		int count = 0;
		if (x >= 0 && x < rows && y >= 0 && y < cols && getsum(x) + getsum(y) <= threshold && flag[x*cols + y] == false)
		{
			flag[x*cols + y] = true;
			count = 1 + Num(threshold, rows, cols, x + 1, y, flag) +
				Num(threshold, rows, cols, x - 1, y, flag) +
				Num(threshold, rows, cols, x, y + 1, flag) +
				Num(threshold, rows, cols, x, y - 1, flag);
		}
		return count;
	}
	int getsum(int num)
	{
		int sum = 0;
		while (num)
		{
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
};