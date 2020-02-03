#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int> > res(1);//�Ƚ��ռ��ŵ���������
		for (int i = 0; i < nums.size(); i++)//����nums�е�Ԫ��
		{
			int n = res.size();//ÿ�����res�Ĵ�С������ΪҪ����һ��Ԫ�ظ�����ÿ��Ԫ�صĺ����
			for (int j = 0; j < n; j++)//��������res�е�Ԫ��
			{
				vector<int> tmp = res[j];//���м�������ȵ���ÿ��res�е�Ԫ�أ���������µ�
				tmp.push_back(nums[i]);//�����µ�Ԫ��
				res.push_back(tmp);//����������������tmp���ַŻ�res��
			}
		}
		return res;//��󷵻�res
	}
};

int main1()
{
	Solution s;
	vector<int> v = { 1, 2, 3 };
	vector<vector<int>>vt = s.subsets(v);
	for (auto &i : vt)
	{
		for (auto &j : i)
		{
			cout << j << ' ';
		}
		cout << endl;
	}


	return 0;
}