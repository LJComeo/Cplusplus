#include <iostream>
#include <vector>
using namespace std;

void Sort2(vector<int>& v)
{
	int min = 0;
	for (int i = 0; i < v.size(); i++)
	{
		min = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[min])
			{
				min = j;
			}
		}
		swap(v[i], v[min]);
	}
}


int main3()
{
	vector<int> v{ 3, 1, 2, 5, 3, 6, 7, 3, 2, 9, 0 };
	Sort2(v);
	for (auto &i : v)
	{
		cout << i << ' ';
	}
	cout << endl;


	return 0;
}