#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		else
		{
			cout << pow(5, n) - 4 << " " << pow(4, n) - 4 + n << endl;
		}
	}
	return 0;
}