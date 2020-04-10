#include <iostream>
#define SIZE 1001

using namespace std;

int main()
{
	int i, j, n, top, temp;
	int stack[SIZE];
	top = 0;
	stack[0] = -1;
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
		{
			cin >> temp;
			if (temp > stack[top])
			{
				stack[++top] = temp;
			}
			else
			{
				int low = 1, high = top;
				int mid;
				while (low <= high)
				{
					mid = (low + high) / 2;
					if (temp > stack[mid])
					{
						low = mid + 1;
					}
					else
					{
						high = mid - 1;
					}
				}
				stack[low] = temp;//使用二分查找找到stack中距离temp最近的位置，直接覆盖
				//这样找的方法，会让每次的位置放置的数字都是在输入的数字中，距离上一个位置最近的数字
				//因此这样的方法就可以得到最长的上升序列
			}
		}

		cout << top << endl;
		top = 0;
	}
	return 0;
}