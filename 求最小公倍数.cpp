#include <iostream>
using namespace std;

//��С������=����֮���������Լ��
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