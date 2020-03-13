#include <iostream>
using namespace std;


class Solution {
public:
    int Sum_Solution(int n)
    {
		int sum = 1;
		n > 1 && (sum = n + Sum_Solution(n - 1));
		return sum;
    }
};



int main2()
{
	
	return 0;
}