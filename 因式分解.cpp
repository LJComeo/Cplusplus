#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		cout << n << " = ";
		for (int i = 2; i <= sqrt(n); i++)
		{
			while (n % i == 0 && n != i)
			{
				cout << i << " * ";
				n /= i;
			}
		}
		cout <<  n << endl;
	}
	return 0;
}