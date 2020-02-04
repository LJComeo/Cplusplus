#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> res;
		if (root == NULL)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty())
		{
			int len = q.size();//len用来表示前一层的元素的个数
			res.push_back(q.front()->val);
			while (len>0)//前一层的元素没有之后，就是这一层的第一个元素，而且这层的第一个元素就是本层的最右边的元素
			{
				TreeNode* temp = q.front();
				q.pop();
				if (temp->right)
					q.push(temp->right);
				if (temp->left)
					q.push(temp->left);
				len--;
			}
		}
		return res;
	}
};

int main()
{



	return 0;
}