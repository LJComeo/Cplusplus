#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		vector<int> v;
		sort(data.begin(), data.end());
		for (int i = 0; i < data.size(); i++)
		{
			
			if (i == data.size() - 1)
			{
				v.push_back(data[i]);
			}
			else if (data[i] == data[i + 1])
			{
				i++;
			}
			else 
			{
				v.push_back(data[i]);
			}
		}
		num1 = &v[0];
		num2 = &v[1];
		cout << *num1 << ',' << *num2 << endl;
	}
};

int main2()
{
	vector<int> vs{ 2, 4, 3, 6, 3, 2, 5, 5 };
	Solution s;
	int *num1 = nullptr;
	int *num2 = nullptr;
	s.FindNumsAppearOnce(vs, num1, num2);


	return 0;
}