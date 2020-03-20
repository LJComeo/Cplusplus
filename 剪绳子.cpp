#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int cutRope(int number)
	{
		if (number <= 1)
			return 0;
		if (number == 2)
			return 1;
		if (number == 3)
			return 2;
		vector<int> v(number + 1);
		//������Ϊ1,2,3ʱ�����ֵ��ȷ���ģ�ֻ������Ϊ4��4���ϣ��ſ��ܷ����仯��Ȼ��ֱ�ӱ�����Ϳ�����
		v[1] = 1;
		v[2] = 2;
		v[3] = 3;
		int Max = 0;
		for (int i = 4; i <= number; i++)
		{
			for (int j = 1; j <= i / 2; j++)
			{
				Max = max(Max, v[j] * v[i - j]);
			}
			v[i] = Max;
		}
		return v[number];
	}
};