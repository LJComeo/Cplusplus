#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A)
	{
		int n = A.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if ((A[i] % 2 != 0) && (A[j] % 2 == 0))
				{
					swap(A[i], A[j]);
				}
			}
		}
		return A;
	}
};

int main2()
{


	return 0;
}