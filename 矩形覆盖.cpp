#include <iostream>
using namespace std;

class Solution {
public:
	int rectCover(int number)
	{
		int n0 = 0;
		int n_2 = 0;
		int n_1 = 1;
		if (number <= 2)
		{
			return number;
		}
		while (number--)
		{
			n0 = n_1 + n_2;
			n_2 = n_1;
			n_1 = n0;
		}
		return n0;
	}
};



int main()
{



	return 0;
}