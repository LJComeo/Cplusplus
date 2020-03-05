#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encryption(string& s)//���ܹ���
{
	string ret(s);
	for (int i = 0; i < s.size(); i++)
	{
		ret[i] = s[i] + 3;
		if ((ret[i] > 'Z' && ret[i] < 'a') || (ret[i] > 'z'))
			ret[i] -= 26;
	}
	return ret;
}

string SolutionDense(string& s)//���ܹ���
{
	string ret(s);
	for (int i = 0; i < s.size(); i++)
	{
		ret[i] = s[i] - 3;
		if (ret[i] < 'A' || (ret[i] > 'Z' && ret[i] < 'a'))
			ret[i] += 26;
	}
	return ret;
}

int main()
{
	string s;
	getline(cin, s);
	string tmp = encryption(s);
	cout << "���ܵĽ����" << tmp << endl;
	string tmp1 = SolutionDense(tmp);
	cout << "���ܵĽ����" << tmp1 << endl;

	/*string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string s1;
	getline(cin, s1);
	string ret(s1);
	int n;
	for (int i = 0; i < s1.size(); i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
			if (s1[i] == s[j])
			{
				if (j <= 2){
					n = j + 26 - 3;
					ret[i] = s[n];
					break;
				}
				else if (j > 2){
					n = (j + 26) % 26 - 3;
					ret[i] = s[n];
				}
			}
		}
	}
	cout <<"���ܺ�Ľ����" <<  ret << endl;*/


	return 0;
}