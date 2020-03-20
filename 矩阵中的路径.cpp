#include <iostream>
using namespace std;

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == nullptr || str == nullptr || rows <= 0 || cols <= 0)
			return false;
		bool* markmatrix = new bool[rows*cols]();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				memset(markmatrix, 0, rows*cols);
				if (Judge(matrix, i, j, rows, cols, str, markmatrix))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool Judge(char* matrix, int x, int y, int rows, int cols, char* str, bool* markmatrix)
	{
		if (*str == 0)
			return true;
		if (matrix[x*cols + y] == *str)
		{
			if (*(str + 1) == 0)
				return true;
			markmatrix[x*cols + y] = true;
			bool a = false; bool b = false; bool c = false; bool d = false;
			if (x + 1 < rows && markmatrix[(x + 1)*cols + y] == false)
				a = Judge(matrix, x + 1, y, rows, cols, str + 1, markmatrix);
			if (x - 1 >= 0 && markmatrix[(x - 1)*cols + y] == false)
				b = Judge(matrix, x - 1, y, rows, cols, str + 1, markmatrix);
			if (y + 1 < cols && markmatrix[x*cols + y + 1] == false)
				c = Judge(matrix, x, y + 1, rows, cols, str + 1, markmatrix);
			if (y - 1 >= 0 && markmatrix[x*cols + y - 1] == false)
				d = Judge(matrix, x, y - 1, rows, cols, str + 1, markmatrix);
			markmatrix[x*cols + y] = false;
			return a || b || c || d;
		}
		else
			return false;
	}

};

int main()
{


	return 0;
}