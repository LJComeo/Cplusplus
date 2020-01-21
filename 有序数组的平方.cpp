#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A)
	{
		for (int i = 0; i < A.size(); i++)
		{
			A[i] *= A[i];
		}
		int n = A.size();
		sort(A.begin(), A.end());
		return A;
	}
};


int main1()
{



	return 0;
}