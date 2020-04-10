#include <iostream>
using namespace std;

int main1()
{
	long arr[21] = { 0 };
	arr[2] = 1;
	arr[3] = 2;
	for (int i = 4; i < 21; i++)
	{
		arr[i] = (i - 1) * (arr[i - 1] + arr[i - 2]);
	}
	int n;
	while (cin >> n)
	{
		cout << arr[n] << endl;
	}
	return 0;
}