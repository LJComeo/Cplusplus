#include <iostream>
using namespace std;

class Solution {
public:
	int Add(int num1, int num2)
	{
		int a = num1 ^ num2;
		int b = (num1 & num2) << 1;
		while (b)
		{
			num1 = a;
			num2 = b;
			a = num1 ^ num2;
			b = (num1 & num2) << 1;
		}
		return a;
	}
};

int main3()
{


	return 0;
}