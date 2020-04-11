#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n;
	int a, b;
	while (cin >> n)
	{
		vector<char> vc(n);
		stack<int> s;
		for (int i = 0; i < n; i++)
		{
			 cin >> vc[i];
		}
		for (int i = 0; i < n; i++)
		{
			if (vc[i] >= '0' && vc[i] <= '9')
				s.push(vc[i] - '0');
			else
			{
				a = s.top();
				s.pop();
				b = s.top();
				s.pop();
				switch (vc[i])
				{
				case '+':s.push(b + a); break;
				case '-':s.push(b - a); break;
				case '*':s.push(b * a); break;
				case '/':s.push(b / a); break;
				}
			}
		}
		cout << s.top() << endl;
	}
	return 0;
}