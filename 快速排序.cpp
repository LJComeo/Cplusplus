#include <iostream>
#include <vector>
#include <set>
using namespace std;

void QuickSort(vector<int> &v,int left,int right)
{
	if (left < right)
	{
		int a = left, b = right, key = v[a];
		while (a < b)
		{
			while (a < b && v[b] >= key)
			{
				b--;
			}
			if (a < b)
			{
				v[a++] = v[b];
			}
			while (a < b && v[a] < key)
			{
				a++;
			}
			if (a < b)
			{
				v[b--] = v[a];
			}
		}
		v[a] = key;
		QuickSort(v, left, a - 1);
		QuickSort(v, a + 1, right);
	}
}

int main()
{
	vector<int> vs{ 3, 2, 5, 1, 6, 7 };
	QuickSort(vs, 0, vs.size() - 1);
	for (auto & i : vs)
	{
		cout << i << ' ';
	}
	cout << endl;

	return 0;
}