// write your code here cpp
#include <iostream>
using namespace std;

int main()
{
	long long arr[91] = { 0 };
	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i < 91; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	int n;
	while (cin >> n)
	{
		cout << arr[n] << endl;
	}
	return 0;
}