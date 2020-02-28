#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
本题用到的是先根遍历，递归
*/

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
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
	{
		vector<vector<int>> vret;
		if (root == nullptr)
			return vret;
		vector<int> vtmp;
		vtmp.push_back(root->val);
		//判断一下，如果expectNumber减去当前的root节点为0，并且此时root是叶子节点，那么就可以将此时的vtmp加入vret中
		if ((expectNumber - root->val) == 0 && root->left == nullptr && root->right == nullptr)
		{
			vret.push_back(vtmp);
		}
		FindPath(root->left, expectNumber - root->val);
		FindPath(root->right, expectNumber - root->val);
		if (vtmp.size() != 0)
		{
			vtmp.pop_back();
		}
		return vret;
	}
};