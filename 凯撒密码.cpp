#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encryption(string& s)//加密过程
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

string SolutionDense(string& s)//解密过程
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
	cout << "加密的结果：" << tmp << endl;
	string tmp1 = SolutionDense(tmp);
	cout << "解密的结果：" << tmp1 << endl;

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
	cout <<"加密后的结果：" <<  ret << endl;*/


	return 0;
}