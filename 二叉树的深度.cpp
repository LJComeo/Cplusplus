#include <iostream>
#include <stack>
#include <queue>
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
	
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		queue<TreeNode*>  qt;
		TreeNode* cur = pRoot;
		qt.push(pRoot);
		int count = 0;
		while (!qt.empty())
		{
			int size = qt.size();
			count++;
			while (size--)
			{
				cur = qt.front();
				qt.pop();
				if (cur->left)
					qt.push(cur->left);
				if (cur->right)
					qt.push(cur->right);
			}
		}
		return count;
	}
};

int main()
{


	return 0;
}