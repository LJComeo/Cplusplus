#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		vector<int> v(n, 0);//��һ��������飬ÿ���ҵ�һ���ͱ��Ϊ-1
		int i = -1;
		int step = 0;
		int count = n;
		while (count > 0)
		{
			i++;
			if (i >= n)//�γ�һ����
				i = 0;
			if (v[i] == -1)//�Ѿ��߹��ĵ㲻���ߣ�ֱ������
				continue;
			step++;//��¼�߹��Ľڵ���
			if (step == m)//�������ñ�ǵĽ�㣬�ͱ�ǣ�����step��գ������ߣ��ڵ�Ķ�����countҲ��һ
			{
				v[i] = -1;
				step = 0;
				count--;
			}
		}
		return i;
	}
};

int main1()
{
	Solution s;
	int tmp = s.LastRemaining_Solution(5, 2);
	cout << tmp << endl;


	return 0;
}