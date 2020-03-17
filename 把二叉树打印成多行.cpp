#include <iostream>
#include <vector>
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
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int>> vvi;
		if (pRoot == nullptr)
			return vvi;
		queue<TreeNode*> qt;
		queue<TreeNode*> qu;
		vector<int> v;
		TreeNode* cur = pRoot;
		qt.push(pRoot);
		while (!qt.empty() || !qu.empty())
		{
			while (!qt.empty())
			{
				cur = qt.front();
				v.push_back(cur->val);
				if (cur->left)
				{
					qu.push(cur->left);
				}
				if (cur->right)
				{
					qu.push(cur->right);
				}
				qt.pop();
			}
			vvi.push_back(v);
			v.clear();
			if (qt.empty() && qu.empty())
				break;
			while (!qu.empty())
			{
				cur = qu.front();
				v.push_back(cur->val);
				if (cur->left)
				{
					qt.push(cur->left);
				}
				if (cur->right)
				{
					qt.push(cur->right);
				}
				qu.pop();
			}
			vvi.push_back(v);
			v.clear();
		}
		return vvi;
	}


};

int main()
{


	return 0;
}