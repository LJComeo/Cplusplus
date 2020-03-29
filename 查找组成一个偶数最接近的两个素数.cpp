#include <iostream>
using namespace std;

bool Judge(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}


int main()
{
	int n;
	while (cin >> n)
	{
		if (Judge(n) == true)
			return 0;
		int mid = n / 2;
		int i;
		for (i = mid; i > 0; i++)
		{
			if (Judge(i) && Judge(n - i))
				break;
		}
		cout << i << endl << n - i << endl;
	}
	return 0;
}