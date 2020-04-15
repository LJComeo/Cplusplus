#include <iostream>
#include <string>
using namespace std;

bool Judge(char strA[], char strB[])
{
	for (int i = 0; i < 256; i++)
	{
		if (strB[i])
		{
			if (strA[i] == '0')
				return false;
			else if (strA[i] < strB[i])
				return false;
		}
	}
	return true;
}

int main1()
{
	string A;
	string B;
	while (cin >> A >> B)
	{
		char strA[256] = { 0 };
		char strB[256] = { 0 };
		for (int i = 0; i < A.size(); i++)
		{
			strA[A[i]]++;
		}
		for (int i = 0; i < B.size(); i++)
		{
			strB[B[i]]++;
		}
		if (Judge(strA, strB))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}