#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum)
	{
		vector<int> vret(2,0);
		if (array.size() <= 1)
			vret.clear();
			return vret;
		int cur = sum * sum;
		for (int i = 0; i < array.size(); i++)
		{
			int tmp = array[i];
			sum -= tmp;
			for (int j = 0; j < array.size(); j++)
			{
				if (j == i)
					continue;
				else
				{
					if (sum == array[j] && ((tmp * array[j]) < cur))
					{
						int cur = array[j];
						vret[0] = tmp;
						vret[1] = cur;
						cur = vret[0] * vret[1];
					}
				}
			}
			sum += tmp;
		}
		if (vret[0] > vret[1])
		{
			int n = vret[0];
			vret[0] = vret[1];
			vret[1] = n;
		}
		if (vret[0] == 0 && vret[1] == 0)
			vret.clear();

		return vret;
	}
};

int main1()
{
	vector<int> v{ 1, 2, 4, 7, 11, 16 };
	Solution s;
	vector<int> ret = s.FindNumbersWithSum(v, 10);
	for (auto & i : ret)
	{
		cout << i << ' ';
	}
	cout << endl;


	return 0;
}