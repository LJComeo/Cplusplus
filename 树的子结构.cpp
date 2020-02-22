#include <iostream>
using namespace std;

/*
���жϵ�ǰ��ͷ�ڵ��valueֵ�Ƿ���ȣ���ȵĻ��Ϳ�һ����ֱ�����Һ����Ƿ����
�����ǰ��h2��ͷ��h1��ͷ�ڵ㲻��ȣ�Ȼ����ж�һ��h1�����Һ��ӽڵ��ǲ�����h2��ͷ�ڵ���ȣ�һ�αȽ�
ֻ�з�����ȵ�������Ż����Serch�������ж��ǲ��Ƿֱ����Һ��Ӷ����
*/

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL)
	{}
};
class Solution
{
public:
	bool Serch(TreeNode* h1, TreeNode* h2)
	{
		if (h2 == nullptr)
			return true;
		if (h1 == nullptr)
			return false;
		if (h1->val == h2->val)
		{
			return Serch(h1->left, h2->left) && Serch(h1->right, h2->right);
		}
		return false;
	}
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if ((pRoot1 == nullptr) || (pRoot2 == nullptr))
			return false;
		return Serch(pRoot1,pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
};

int main5()
{



	return 0;
}