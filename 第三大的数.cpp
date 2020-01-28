#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
	int thirdMax(vector<int>& nums)
	{
		set<int> hash_set;

		for (auto n : nums){
			hash_set.insert(n);
			if (hash_set.size()>3)//这种方法就可以保证set在取的时候可以直接取begin
				hash_set.erase(*(hash_set.begin()));
		}
		if (hash_set.size()<3)
			return *(hash_set.rbegin());
		else
			return *(hash_set.begin());
	}
};

int main()
{



	return 0
}