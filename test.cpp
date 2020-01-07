#include <iostream>
using namespace std;
//using namespace lpl;
//using namespace lck;
//namespace lpl
//{
//	int func(int a, int b)
//	{
//		return a + b;
//	}
//}
//namespace lck
//{
//	int func(int a, int b)
//	{
//		return a + b;
//	}
//}

int test()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

	for (auto &i : arr)
	{
		cout << i;
	}

	return 0;
}