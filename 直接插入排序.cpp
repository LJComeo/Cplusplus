#include <iostream>
#include <vector>
using namespace std;


/*
直接插入排序：从第二个元素开始，每次都讲这个元素查到前面的对应的位置
*/

void Sort1(vector<int>& v)
{
	int i, j;
	for (i = 1; i < v.size(); i++)//i从1开始，因为第一个数字不用排序  直接插入就行了
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