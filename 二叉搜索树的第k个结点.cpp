#include <iostream>
#include <stack>
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
	TreeNode* KthNode(TreeNode* pRoot, int k)
	{
		if (pRoot == nullptr)
			return nullptr;
		if (k <= 0)
			return nullptr;
		vector<int> v;
		stack<TreeNode*> st;
		TreeNode* cur = pRoot;
		while (cur || !st.empty())
		{
			for (; cur; cur = cur->left)
			{
				st.push(cur);
			}
			cur = st.top();
			v.push_back(cur->val);
			st.pop();
			cur = cur->right;
		}
		if (k > v.size())
			return nullptr;
		TreeNode* ret = new TreeNode(v[k - 1]);
		return ret;
	}


};

int main2()
{


	return 0;
}