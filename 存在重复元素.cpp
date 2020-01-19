#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		set<int> s(nums.begin(),nums.end());
		return s.size() != nums.size();
	}
};


int main1()
{



	return 0;
}