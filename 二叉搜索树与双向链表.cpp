#include <iostream>
#include <stack>
using namespace std;


struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {
	}
};
class Solution
{
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		stack<TreeNode*> stnode;
		TreeNode* cur = nullptr;
		TreeNode* tmp = nullptr;
		bool flag = true;
		while (pRootOfTree || !stnode.empty())
		{
			while (pRootOfTree)
			{
				stnode.push(pRootOfTree);
				pRootOfTree = pRootOfTree->left;
			}

			pRootOfTree = stnode.top();
			if (flag)
			{
				cur = pRootOfTree;
				tmp = cur;
				flag = false;
			}
			else
			{
				tmp->right = pRootOfTree;
				pRootOfTree->left = tmp;
				tmp = pRootOfTree;
			}
			stnode.pop();
			pRootOfTree = pRootOfTree->right;
		}
		return cur;
	}
};


int main()
{




	return 0;
}