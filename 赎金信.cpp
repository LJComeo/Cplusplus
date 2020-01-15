#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

//判断第一个字符串中的字符能不能由第二个字符串中的字符组成

/*
此题是一个映射问题，主要使用的方法是map，但是不使用普通的map，是因为普通
的map不能重复，但是本题可以，所以就使用unordered_map，首先记录一下杂志字符串
然后将赎金信中的找到，最后只要有任意一个字符减的小于0后，就说明没有完全包含
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