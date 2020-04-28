#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream ifs("test.txt", ios::binary);//�Զ�+�����ƴ��ļ�
	string line;//���ж��ļ�
	if (ifs.is_open() == false)
	{
		cout << "open file error" << endl;
		return -1;
	}
	int lineno = 1;
	int pos1, pos2;
	while (getline(ifs, line))
	{
		pos1 = line.find('a');
		pos2 = line.find('b');
		if (pos1 < 0 || pos2 < 0)
		{
			lineno++;
		}
	}
	cout << lineno <<','<< pos1 + 1 << ',' <<  pos2 + 1 << endl;
	return 0;
}