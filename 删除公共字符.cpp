#include <iostream>
#include <string>
using namespace std;

/*
����һ��ɾ�������ַ���demo��
�ⷨ��������һ�����飬��¼str2�г��ֵ��ַ���
Ȼ����һ��string������str1������str2���ظ��Ĳ��ֶ��ŵ����string�У�Ȼ�󷵻����string
*/

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
		{
			ret += str1[i];
		}
	}
	cout << ret << endl;
	return 0;
}