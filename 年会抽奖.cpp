#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main1()
{
	long long num[21] = { 0, 0, 1 };
	long long sum[21] = { 0, 1, 2 };
	for (int i = 3; i < 21; i++)
	{
		num[i] = (i - 1)*(num[i - 1] + num[i - 2]);
		sum[i] = i * sum[i - 1];
	}
	int n;
	while (cin >> n)
	{
		printf("%.2lf%c\n", 1.0 * num[n] / sum[n] * 100, '%');
	}
	return 0;
}