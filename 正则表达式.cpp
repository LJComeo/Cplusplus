#include <iostream>
using namespace std;

class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')//如果两个字符串都是空的，则返回true
			return true;
		if (*str != '\0'  && *pattern == '\0')//如果第一个字符串是非空，但是第二个字符串为空，则肯定不可以匹配成功，返回false，反之却有可能
			return false;
		if (*(pattern + 1) != '*')//*的情况比较复杂，就使用*来比较
		{
			if (*str == *pattern || (*pattern == '.' && *str != '\0'))//当下一个不是*时，如果当前的两个字符相等或者第二个字符是 . 第一个非空，那么直接两个字符串都+1然后继续判断即可
				return match(str + 1, pattern + 1);
			else
				return false;//不满足if的条件则匹配失败
		}
		else
		{
			if (*str == *pattern || (*pattern == '.' && *str != '\0'))//如果下一个是* ，但是*可以匹配多个或者0个，因此继续讨论
				return match(str, pattern + 2) || match(str + 1, pattern);//如果此时当前两个字符匹配的情况下，下一个是*字符，情况1：如果*代表的是0个，那么直接跨越第二个字符串的两个字符即可重新判断；
			//情况2：如果代表的是一个或者多个，那就将第一个字符串向后移动一位，进行判断后续是否相等;（之所以将匹配一个与多个放在一起，是因为多个可以看成是多个1的组合，匹配一个右移一位）
			//情况1与情况2只要有一个满足，就可以继续匹配下去
			else
				return match(str, pattern + 2);//如果当前的字符不匹配，那么我们就是*之前变成0个的情况，第二个字符串同样向右移动两个字符
		}
	}
};

int main()
{





	return 0;
}