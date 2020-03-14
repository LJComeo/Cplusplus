#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A)
	{
		int n = A.size();
		vector<int> ret(A);
		if (A.empty())
			return ret;
		if (n == 1)
		{
			ret.push_back(A[0]);
			return ret;
		}
		if (n == 2)
		{
			ret[0] = A[1];
			ret[1] = A[0];
			return ret;
		}
		if (n > 2)
		{
			int tmp = 1;
			for (int i = 1; i < n - 1; i++)
			{
				tmp *= A[i];
			}
			ret[0] = tmp * A[n - 1];
			int cur = 1;
			for (int i = 1; i < n - 1; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (i != j)
						cur *= A[j];
				}
				ret[i] = cur;
				cur = 1;
			}
			ret[n - 1] = tmp * A[0];
		}
		return ret;
	}
};

int main2()
{



	return 0;
}