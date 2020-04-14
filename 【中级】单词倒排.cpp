#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	string tmp;
	for (int i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i]))
		{
			continue;
		}
		while (i < str.size() && (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			tmp.push_back(str[i]);
			i++;
		}
		if (i < str.size() - 1)
			tmp.push_back(' ');
	}
	reverse(tmp.begin(), tmp.end());
	int j = 0,k = 0;
	while (1)
	{
		k = tmp.find( ' ',j );
		if (k >= 0)
			reverse(tmp.begin() + j, tmp.begin() + k);
		else
		{
			reverse(tmp.begin() + j, tmp.end());
			break;
		}
		j = k + 1;
	}
	cout << tmp << endl;

	return 0;
}