#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {

		vector<char> ch = chars;
		chars.clear();
		int count = 1;  //ͳ�������ַ�������
		for (int i = 0; i < ch.size() - 1; i++)
		{
			if (ch[i] == ch[i + 1])//ǰ�������ַ���ͬ
				count++;
			else
			{
				chars.push_back(ch[i]);//ǰ�������ַ���ͬ
				if (count > 1)
				{
					string s(to_string(count));
					for (auto c : s)
						chars.push_back(c);
				}
				count = 1;
			}
		}

		chars.push_back(ch[ch.size() - 1]);
		if (count > 1)
		{
			string s(to_string(count));
			for (auto c : s)
				chars.push_back(c);
		}
		return chars.size();
	}
};

int main()
{



	return 0;
}