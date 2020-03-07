#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



//1,2,3,4,5,6,8,9,10
class Solution {
public:
	int GetUglyNumber_Solution(int index)
	{
		if (index == 0)
			return 0;
		if (index == 1)
			return 1;
		vector<int> v(index);
		v[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0;//将丑数分成三类，一直乘2，一直乘3，一直乘5
		for (int i = 1; i < index; i++)
		{
			v[i] = min(v[t2] * 2, min(v[t3] * 3, v[t5] * 5));
			//如果发现现在的v[i]与v[t2]\v[t3]\v[t5]中的任何一个相等对应的t2\t3\t5需要++；下次运算的时候就从这里开始了
			if (v[i] == v[t2] * 2)
				t2++;
			if (v[i] == v[t3] * 3)
				t3++;
			if (v[i] == v[t5] * 5)
				t5++;
		}
		return v[index - 1];
	}
};


int main()
{
	Solution s;
	int tmp = s.GetUglyNumber_Solution(7);
	cout << tmp << endl;


	return 0;
}