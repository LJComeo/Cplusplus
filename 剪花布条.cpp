#include <iostream>
#include <string>
using namespace std;

int main1()
{
	string sr;
	string tr;
	while (cin >> sr >> tr)
	{
		int count = 0;
		int pos = sr.find(tr);
		while (pos >= 0)
		{
			count++;
			pos = sr.find(tr, pos + tr.size());
		}
		cout << count << endl;
	}
	return 0;
}