#include <iostream>
using namespace std;

class Solution {
public:
	// Parameters:
	//        numbers:     an array of integers
	//        length:      the length of array numbers
	//        duplication: (Output) the duplicated number in the array number
	// Return value:       true if the input is valid, and there are some duplications in the array number
	//                     otherwise false
	bool duplicate(int numbers[], int length, int* duplication) {
		if (length == 0 || length == 1)
			return false;
		int buf[256] = { 0 };
		for (int i = 0; i < length; i++)
		{
			buf[numbers[i]]++;
		}
		for (int i = 0; i < length; i++)
		{
			if (buf[numbers[i]] > 1)
			{
				duplication[0] = numbers[i];
				return true;
			}
		}
		return false;
	}
};

int main1()
{



	return 0;
}