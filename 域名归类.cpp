#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, size;
	string pre = "http://";

	while (cin >> n)
	{
		string line, str1, str2;
		map<string, vector<string> > book;
		map<vector<string>, vector<string> > book2;
		for (int i = 0; i < n; ++i)
		{
			cin >> line;
			auto pos1 = line.find("//") + 2, pos2 = line.find("/", pos1);
			if (pos2 == string::npos)
				pos2 = line.size();
			str1 = line.substr(pos1, pos2 - pos1);
			str2 = line.substr(pos2);
			if (find(book[str1].begin(), book[str1].end(), str2) == book[str1].end())
				book[str1].push_back(str2);
		}
		for (auto &iter : book)
		{
			sort(iter.second.begin(), iter.second.end());
			book2[iter.second].push_back(iter.first);
		}
		size = 0;
		for (auto &iter : book2)
		{
			if (iter.second.size() > 1)
				++size;
		}
		cout << size << endl;
		for (auto &iter : book2)
		{
			if (iter.second.size() > 1)
			{
				cout << pre + iter.second[0];
				for (int i = 1; i < iter.second.size(); ++i)
					cout << " " << pre + iter.second[i];
				cout << endl;
			}
		}
	}

	return 0;
}