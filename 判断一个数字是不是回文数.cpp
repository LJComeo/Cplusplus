#include <iostream>
using namespace std;


class Solution {
public:
	bool isPalindrome(int x)
	{
		int result = 0;
		int y = x;
		if (x<0){
			return false;
		}
		else if (x == 0){
			return true;
		}
		else {
			while (x != 0){
				result = result * 10 + x % 10;
				x /= 10;
			}
			if (y == result){
				return true;
			}
			else {
				return false;
			}
		}
	}
};

int main()
{
	Solution s;
	cout << s.isPalindrome(2147483647) << endl;


	return 0;
}