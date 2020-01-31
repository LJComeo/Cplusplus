#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int compress(vector<char>& chars) {

		vector<char> ch = chars;
		chars.clear();
		int count = 1;  //统计连续字符的数量
		for (int i = 0; i < ch.size() - 1; i++)
		{
			if (ch[i] == ch[i + 1])//前后两个字符相同
				count++;
			else
			{
				chars.push_back(ch[i]);//前后两个字符不同
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