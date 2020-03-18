#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> v;
	void Insert(int num)
	{
		v.push_back(num);
		sort(v.begin(), v.end());
	}

	double GetMedian()
	{
		double ret = 0;
		if (v.size() % 2 == 0)
		{
			ret = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
		}
		else
		{
			ret = v[v.size() / 2.0];
		}
		return ret;
	}

};

int main1()
{


	return 0;
}