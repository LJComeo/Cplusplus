#include <iostream>
#include <cstdio>
using namespace std;

struct S
{
	int a;
	int b;
	bool operator == (const S &rhs);
};

bool S::operator == (const S &rhs)
{
	return ((a == rhs.a) && (b == rhs.b));
}

int main()
{
	//S *p1 = (S*)malloc(4 * sizeof(S));
	//S *p2 = new S;
	struct S s1, s2;
	s1.a = 1;
	s1.b = 2;
	s2.a = 1;
	s2.b = 2;
	if (s1 == s2)
	{
		cout << "两个结构体相等" << endl;
	}
	else
	{
		cout << "两个结构体不相等" << endl;
	}
	return 0;
}