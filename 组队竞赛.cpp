#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
����һ����Ӿ�����demo����ӣ�ʹÿ���ˮƽֵ�ﵽ���(ˮƽֵΪÿ��Ĵδ�ֵ)
����˼·��
������3����һ�ӣ�����֮���±�Ϊ0-��n-1���ľ�����n���������С��ֵ��
Ȼ����±�Ϊn��λ�ÿ�ʼ���ǵ�һ��С��Ĵδ�����ÿ���±�+2��ԭ����������ĵ�һ���Ǵδ󣬵��ǵڶ���������������
Ȼ����Щ����ȫ����������֪��i = 3 * n - 2;��ʱȡ��������һ���δ�����֡�
*/

int main1()
{
	int n;
	while (cin >> n)
	{
		long long sum = 0;
		vector<int> v;
		v.resize(3 * n);
		for (int i = 0; i < (3 * n); i++)
		{
			cin >> v[i];
		}

		sort(v.begin(), v.end());
		for (int i = n; i < (3 * n - 2); i += 2)
		{
			sum += v[i];
		}
		cout << sum << endl;
	}
	return 0;
}
