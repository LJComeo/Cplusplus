#include <iostream>
#include <queue>
using namespace std;


struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {}
};
class Solution 
{
public:
	void Mirror(TreeNode *pRoot)
	{
		if (!pRoot)
		{
			return;
		}
		swap(pRoot->left, pRoot->right);//不论存在不存在左右孩子，直接交换就行了，不存在的就是空，一样的需要交换
		if (pRoot->left)
		{
			Mirror(pRoot->left);
		}
		if (pRoot->right)
		{
			Mirror(pRoot->right);
		}
	}
};

int main6()
{



	return 0;
}