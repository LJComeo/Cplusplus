#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		stack<TreeNode*> s;
		stack<TreeNode*> q;
		vector<vector<int>> vvret;
		vector<int> v;
		if (pRoot == nullptr)
			return vvret;
		q.push(pRoot);
		TreeNode* cur = pRoot;
		int flag = 2;
		while (!q.empty() || !s.empty())
		{
			while (flag % 2 == 0 && !q.empty())
			{
				cur = q.top();
				v.push_back(cur->val);
				if (cur->left)
				{
					s.push(cur->left);
				}
				if (cur->right)
				{
					s.push(cur->right);
				}
				q.pop();
			}
			vvret.push_back(v);
			v.clear();
			flag++;
			if (q.empty() && s.empty())
				break;
			while (flag % 2 != 0 && !s.empty())
			{
				cur = s.top();
				v.push_back(cur->val);
				if (cur->right)
				{
					q.push(cur->right);
				}
				if (cur->left)
				{
					q.push(cur->left);
				}
				s.pop();
			}
			vvret.push_back(v);
			v.clear();
			flag++;
		}
		return vvret;
	}

};

int main()
{



	return 0;
}