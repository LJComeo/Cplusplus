#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	bool isSymmetrical(TreeNode* pRoot)
	{
		return IsSymmetrical(pRoot, pRoot);//将根节点分成两个结点，然后分别递归的判断两个节点的对称情况以及他们孩子的对称情况
	}
	bool IsSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == nullptr && pRoot2 == nullptr)
			return true;
		if (pRoot1 == nullptr || pRoot2 == nullptr)
			return false;
		if (pRoot1->val != pRoot2->val)
			return false;
		return IsSymmetrical(pRoot1->left, pRoot2->right) && IsSymmetrical(pRoot1->right, pRoot2->left);
	}
};

int main()
{


	return 0;
}