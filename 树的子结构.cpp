#include <iostream>
using namespace std;

/*
先判断当前的头节点的value值是否相等，相等的话就看一下其分别的左右孩子是否相等
如果当前的h2的头与h1的头节点不相等，然后就判断一下h1的左右孩子节点是不是与h2的头节点相等，一次比较
只有发现相等的情况，才会进入Serch函数来判断是不是分别左右孩子都相等
*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL)
	{}
};
class Solution
{
public:
	bool Serch(TreeNode* h1, TreeNode* h2)
	{
		if (h2 == nullptr)
			return true;
		if (h1 == nullptr)
			return false;
		if (h1->val == h2->val)
		{
			return Serch(h1->left, h2->left) && Serch(h1->right, h2->right);
		}
		return false;
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if ((pRoot1 == nullptr) || (pRoot2 == nullptr))
			return false;
		return Serch(pRoot1,pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
};

int main5()
{



	return 0;
}