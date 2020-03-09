#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k)
	{
		int count = 0;
		for (int i = 0; i < data.size(); i++)
		{
			if (data[i] == k)
			{
				count++;
			}
		}
		return count;
	}
};

int main3()
{



	return 0;
}