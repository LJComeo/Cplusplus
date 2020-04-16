#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct ErrorRecord{
	string name;
	int line;
	int num;
};
int main()
{
	vector<ErrorRecord> record;
	string name_temp;
	int line_temp;
	while (cin >> name_temp >> line_temp)
	{
		bool flag = 1;
		int pos = name_temp.find_last_of('\\');
		name_temp = name_temp.substr(pos + 1);
		if (name_temp.size() > 16)
			name_temp = name_temp.substr(name_temp.size() - 16);

		for (int i = 0; i < record.size(); i++)
		{
			if (name_temp == record[i].name && line_temp == record[i].line)
			{
				record[i].num++;
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			ErrorRecord record_temp;
			record_temp.name = name_temp;
			record_temp.line = line_temp;
			record_temp.num = 1;
			record.push_back(record_temp);
			flag = 1;
		}
	}
	int i = 0;
	if (record.size() > 8)
		i = record.size() - 8;
	for (; i < record.size(); i++)
	{
		cout << record[i].name << ' ' << record[i].line << ' ' << record[i].num << endl;
	}

	return 0;
}