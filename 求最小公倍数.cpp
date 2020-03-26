#include <iostream>
using namespace std;

//最小公倍数=两数之积乘以最大公约数
int gcb(int a,int b)
{
	int c;
	while (c = a % b)
	{
		a = b;
		b = c;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a*b / gcb(a, b) << endl;
	}

	return 0;
}