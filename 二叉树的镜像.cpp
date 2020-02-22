#include <iostream>
#include <queue>
using namespace std;


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
	void Mirror(TreeNode *pRoot)
	{
		if (!pRoot)
		{
			return;
		}
		swap(pRoot->left, pRoot->right);//���۴��ڲ��������Һ��ӣ�ֱ�ӽ��������ˣ������ڵľ��ǿգ�һ������Ҫ����
		if (pRoot->left)
		{
			Mirror(pRoot->left);
		}
		if (pRoot->right)
		{
			Mirror(pRoot->right);
		}
	}
};

int main6()
{



	return 0;
}