#include <iostream>
#include <vector>
using namespace std;

//5 7 6 9 11 10 8

/*
二叉搜索树的后序遍历，root一定是最后一个元素，然后可以使用递归的原因是，将左右子树分别取出来遍历，
如果每个结点及其子树都是二叉搜索树，那么这个序列就是二叉搜索树的后序遍历序列
*/
class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		return bst(sequence,0, sequence.size() - 1);
	}
	bool bst(vector<int> sequence,int begin, int end)
	{
		if (sequence.empty())
			return false;
		if (begin > end)
			return false;
		int root = sequence[end];
		int i = begin;
		for (; i < end; i++)
		{
			if (sequence[i] > root)
				break;
		}
		for (int j = i; j < end; j++)
		{
			if (sequence[j] < root)
				return false;
		}
		bool left = true;
		if (i > begin)
			left = bst(sequence,0,i - 1);
		bool right = true;
		if (i < end - 1)
			right = bst(sequence,i, end - 1);
		return (left && right);
	}
};

int main1()
{
	Solution s;
	vector<int> v{ 7, 4, 6, 5 };
	cout << s.VerifySquenceOfBST(v) << endl;

	return 0;
}