#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val)
	{
		int tmp = 0;
		vector<int> ::iterator it = nums.begin();
		while (it != nums.end())
		{
			if (*it == val)
			{
				it = nums.erase(it);
			}
			else
			{
				++it;
			}
		}
		tmp = nums.size();
		return tmp;
	}
};


int main()
{


	return 0;
}