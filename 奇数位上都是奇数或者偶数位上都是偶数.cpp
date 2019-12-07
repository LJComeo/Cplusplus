#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*  奇数位上都是奇数或者偶数位上都是偶数
	*  输入：数组arr，长度大于2
	*  len：arr的长度
	*  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		//每次与最后一个元素比较，如果为奇数，则与奇数位上交换，下标+2,如果为偶数，同理
		//奇偶位上的数依次填入
		while (i<len && j<len)
		{
			if (arr[len - 1] % 2 == 0)
			{
				swap(arr[len - 1], arr[i]);
				i += 2;
			}
			else
			{
				swap(arr[len - 1], arr[j]);
				j += 2;
			}
		}
	}
};
int main2()
{


	return 0;
}