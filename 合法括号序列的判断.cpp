#include <iostream>
#include <string>
using namespace std;

class Parenthesis {
public:
	bool chkParenthesis(string A, int n)
	{
		int flag = 0;
		if (n <= 1)
			return false;
		for (int i = 0; i < n; i++)
		{
			if (A[i] != '(' && A[i] != ')')
				return false;
			if (A[i] == '(')
				flag++;
			else
				flag--;
		}
		if (flag == 0)
			return true;
		else
			return false;
	}
};

int main()
{
	string s = "()()(((())))";
	Parenthesis p;
	cout << p.chkParenthesis(s, 12);

	return 0;
}