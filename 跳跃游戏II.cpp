#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution
{
public:
	int jump(vector<int>& nums)
	{
		int maxPos = 0, n = nums.size(), end = 0, step = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			if (i <= maxPos)
			{
				maxPos = max(maxPos, i + nums[i]);//���ϵ�Ѱ����Զ�����λ��
				if (i == end)//����ʱ��ǰ��λ�ñ������߽�ʱ���൱���ҵ�����һ���ķ��������±߽�
				{
					end = maxPos;
					++step;
				}
			}
		}
		return step;
	}
};


int main()
{
	vector<int> v{ 2, 3, 1, 1, 4 };
	Solution s;
	cout << s.jump(v) << endl;

	return 0;
}