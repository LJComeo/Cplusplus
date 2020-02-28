#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
�����õ������ȸ��������ݹ�
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
		//�ж�һ�£����expectNumber��ȥ��ǰ��root�ڵ�Ϊ0�����Ҵ�ʱroot��Ҷ�ӽڵ㣬��ô�Ϳ��Խ���ʱ��vtmp����vret��
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