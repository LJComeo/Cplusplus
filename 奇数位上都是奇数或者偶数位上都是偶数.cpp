#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0, j = 1;
		//ÿ�������һ��Ԫ�رȽϣ����Ϊ��������������λ�Ͻ������±�+2,���Ϊż����ͬ��
		//��żλ�ϵ�����������
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