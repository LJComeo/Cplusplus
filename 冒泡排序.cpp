#include <iostream>
#include <vector>
using namespace std;

/*
ð�������㷨��
�����ҽ��бȽϣ�һ��һ��Ľ�����ð�����
*/

void Sort(vector<int> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				int tmp = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tmp;
			}
		}
	}
}

int main1()
{
	vector<int> vi{ 3, 2, 1, 7, 4, 5, 8, 1, 5, 0, 2, 4 };
	Sort(vi);
	for (auto &i : vi)
	{
		cout << i << ' ';
	}
	cout << endl;

	return 0;
}
