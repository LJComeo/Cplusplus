#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		vector<int> v(n, 0);//找一个标记数组，每当找到一个就标记为-1
		int i = -1;
		int step = 0;
		int count = n;
		while (count > 0)
		{
			i++;
			if (i >= n)//形成一个环
				i = 0;
			if (v[i] == -1)//已经走过的点不在走，直接跳过
				continue;
			step++;//记录走过的节点数
			if (step == m)//如果到达该标记的结点，就标记，并且step清空，重新走，节点的额总数count也减一
			{
				v[i] = -1;
				step = 0;
				count--;
			}
		}
		return i;
	}
};

int main1()
{
	Solution s;
	int tmp = s.LastRemaining_Solution(5, 2);
	cout << tmp << endl;


	return 0;
}