#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//�жϵ�һ���ַ����е��ַ��ܲ����ɵڶ����ַ����е��ַ����

/*
������һ��ӳ�����⣬��Ҫʹ�õķ�����map�����ǲ�ʹ����ͨ��map������Ϊ��ͨ
��map�����ظ������Ǳ�����ԣ����Ծ�ʹ��unordered_map�����ȼ�¼һ����־�ַ���
Ȼ��������е��ҵ������ֻҪ������һ���ַ�����С��0�󣬾�˵��û����ȫ����
*/
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char, int>map;
		for (int i = 0; i<magazine.length(); i++)
			map[magazine[i]] += 1;
		for (int i = 0; i<ransomNote.length(); i++)
		{
			map[ransomNote[i]] -= 1;
			if (map[ransomNote[i]]<0) return false;
		}
		return true;
	}
};

int main2()
{




	return 0;
}