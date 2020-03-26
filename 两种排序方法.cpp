#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	vector<string> vs;
	
	while (cin >> n)
	{
		vs.resize(n);
		for (auto &i : vs)
		{
			cin >> i; 
		}
		bool flag1 = true, flag2 = true;

		for (int i = 1; i < n; i++)
		{
			if (vs[i - 1] >= vs[i])
			{
				flag1 = false;
				break;
			}
		}

		for (int i = 1; i < n; i++)
		{
			if (vs[i - 1].size() >= vs[i].size())
			{
				flag2 = false;
				break;
			}
		}

		if (!flag1 && !flag2)
			cout << "none" << endl;
		else if (flag1 && flag2)
			cout <<"both" << endl;
		else if (flag1 && !flag2)
			cout << "lexicographically" << endl;
		else if (!flag1 && flag2)
			cout << "lengths" << endl;
	}
	return 0;
}