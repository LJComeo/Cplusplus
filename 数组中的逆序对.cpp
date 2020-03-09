#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int InversePairs(vector<int> data)//在归并排序中找出逆序对的大小
	{
		if (data.empty())
			return 0;
		vector<int> tmp(data);
		long long count = Count(data, tmp, 0, data.size() - 1);
		return count % 1000000007;
	}
	long long Count(vector<int>& data, vector<int>& tmp, int start, int end)
	{
		
		if (start == end)
		{
			tmp[start] = data[start];
			return 0;
		}
		long long left;
		long long right;
		int mid = (start + end) / 2;
		left = Count(tmp,data,  start, mid);
		right = Count(tmp,data, mid + 1, end);


		long long count = 0;
		int i = mid;
		int j = end;
		int k = end;
		while (i >= start && j >= mid + 1)
		{
			if (data[i] > data[j])
			{
				tmp[k--] = data[i--];
				count = count + (j - mid);
				
			}
			else
			{
				tmp[k--] = data[j--];
			}
		}

		for (; i >= start; i--)
			tmp[k--] = data[i];
		for (; j >= mid + 1; j--)
			tmp[k--] = data[j];
		return count + left + right;
	}
};

int main1()
{
	vector<int> v{ 364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 407, 416, 366, 315, 301, 601,
		650, 418, 355, 460, 505, 360, 965, 516, 648, 727, 667, 465, 849, 455, 181, 486, 149, 588, 233, 
		144, 174, 557, 67, 746, 550, 474, 162, 268, 142, 463, 221, 882, 576, 604, 739, 288, 569, 256, 
		936, 275, 401, 497, 82, 935, 983, 583, 523, 697, 478, 147, 795, 380, 973, 958, 115, 773, 870, 
		259, 655, 446, 863, 735, 784, 3, 671, 433, 630, 425, 930, 64, 266, 235, 187, 284, 665, 874, 80, 
		45, 848, 38, 811, 267, 575 };
	Solution s;
	cout << s.InversePairs(v);


	return 0;
}