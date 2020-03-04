#include <iostream>
using namespace std;



class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		int high = 0, w;
		int low = 0;
		int i = -1;
		do
		{
			i++;
			int m = pow(10, i);
			high = n / m;
			w = high % 10;
			high /= 10;
			if (i == 0)
				low = 0;
			else
				low = n % m;
			if (w < 1)
				count += high * pow(10, i);
			else if (w == 1)
				count += high * pow(10, i) + low + 1;
			else
				count += (high + 1) * pow(10, i);
		} while (high != 0);
		return count;
	}
};

int main()
{



	return 0;
}