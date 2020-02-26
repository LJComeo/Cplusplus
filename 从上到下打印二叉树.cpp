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
	vector<int> PrintFromTopToBottom(TreeNode* root)
	{
		queue<TreeNode*> qu;
		vector<int> v;
		if (root == nullptr)
			return v;
		TreeNode* cur;
		qu.push(root);
		while (!qu.empty())
		{
			cur = qu.front();
			v.push_back(cur->val);
			if (cur->left)
			{
				qu.push(cur->left);
			}
			if (cur->right)
			{
				qu.push(cur->right);
			}
			qu.pop();
		}
		return v;
	}
};


int main()
{
	Solution s;
	
	


	return 0;
}