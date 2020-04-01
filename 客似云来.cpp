#include <iostream>
using namespace std;

int main()
{
	int from, to;
	long long count = 0;
	long long arr[82] = { 0 };
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= 80; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	while (cin >> from >> to)
	{
		if (from != to)
		{
			for (int i = from; i <= to; i++)
			{
				count += arr[i];
			}
			cout << count << endl;
		}
		else
		{
			cout << arr[from] << endl;
		}
	}

	return 0;
}