#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points)
	{
		if (points.size() == 0)
			return 0;
		sort(points.begin(), points.end(), [](const vector<int>& u, const vector<int>& v) {
			return u[1] < v[1];
		});
		int right = points[0][1];
		int count = 1;
		for (int i = 1; i < points.size(); i++)
		{
			if (right < points[i][0])
			{
				right = points[i][1];
				count++;
			}
		}
		return count;
	}
};

int main()
{


	return 0;
}