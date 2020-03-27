#include <iostream>
using namespace std;

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int tmp = 0, cur = 0;
		while (B)
		{
			tmp = A ^ B;
			cur = (A & B) << 1;
			A = tmp;
			B = cur;
		}
		return A;
	}
};

int main()
{


	return 0;
}