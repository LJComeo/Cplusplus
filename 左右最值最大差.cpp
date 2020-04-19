#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxGap {
public:
	int findMaxGap(vector<int> A, int n) {
		int max = A[0];
		for (int i = 1; i<n; i++)
		{
			if (A[i]>max)
				max = A[i];
		}
		int minnum = min(A[0], A[n - 1]);
		return max - minnum;
	}
};
int main()
{

	return 0;
}