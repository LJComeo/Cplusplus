#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()) 
			return 0;
		int left = 0, right = rotateArray.size() - 1;
		while (left < right) {
			//ȷ���������Ƿ�������1,1,2,4,5,..,7�ķǵݼ�����
			if (rotateArray[left] < rotateArray[right]) 
				return rotateArray[left];

			int mid = left + (right - left) / 2;
			//����������Ϊ��������
			if (rotateArray[left] < rotateArray[mid])
				left = mid + 1;
			//����Ұ�����Ϊ��������
			else if (rotateArray[mid] < rotateArray[right])
				right = mid;
			//����rotateArray[left] == rotateArray[mid] == rotateArray[right]
			else {
				++left;
			}
		}
		return rotateArray[left];
	}
};

int main()
{



	return 0;
}