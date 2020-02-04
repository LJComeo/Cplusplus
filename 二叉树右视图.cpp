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
			int len = q.size();//len������ʾǰһ���Ԫ�صĸ���
			res.push_back(q.front()->val);
			while (len>0)//ǰһ���Ԫ��û��֮�󣬾�����һ��ĵ�һ��Ԫ�أ��������ĵ�һ��Ԫ�ؾ��Ǳ�������ұߵ�Ԫ��
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