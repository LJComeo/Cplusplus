#include <iostream>
#include <vector>
using namespace std;


/*
ֱ�Ӳ������򣺴ӵڶ���Ԫ�ؿ�ʼ��ÿ�ζ������Ԫ�ز鵽ǰ��Ķ�Ӧ��λ��
*/

void Sort1(vector<int>& v)
{
	int i, j;
	for (i = 1; i < v.size(); i++)//i��1��ʼ����Ϊ��һ�����ֲ�������  ֱ�Ӳ��������
	{
		int tmp = v[i];
		for (j = i; j > 0 && v[j - 1] > tmp; j--)
		{
			v[j] = v[j - 1];
		}
		v[j] = tmp;
	}
}



int main2()
{
	vector<int> v{ 3, 1, 2, 5, 3, 6, 7, 3, 2, 9, 0 };
	Sort1(v);
	for (auto &i : v)
	{
		cout << i << ' ';
	}
	cout << endl;


	return 0;
}