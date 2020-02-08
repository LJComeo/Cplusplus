#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
这是一个组队竞赛的demo：组队，使每组的水平值达到最大(水平值为每组的次大值)
本题思路：
首先是3个人一队，排序之后，下标为0-（n-1）的就是这n个队伍的最小的值；
然后从下标为n的位置开始就是第一个小组的次大数，每次下标+2的原因就是碰见的第一个是次大，但是第二个就是最大的数；
然后将这些数字全部加起来，知道i = 3 * n - 2;此时取到了最后的一个次大的数字。
*/

int main1()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> v;
		v.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());
		for (int i = n; i < (3 * n - 2); i += 2)
		{
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}
