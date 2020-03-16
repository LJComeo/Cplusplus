#include <iostream>
#include <stack>
#include <vector>
using namespace std;


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		TreeLinkNode* cur = pNode;
		if (cur->right)//查看右孩子是否存在
		{
			if (cur->right->left)//如果存在的话，下一个结点就是右孩子的最左结点
			{
				TreeLinkNode* tmp = cur->right->left;
				for (; tmp; tmp = tmp->left)
				{
					if (tmp->left == nullptr)
						break;
				}
				return tmp;
			}
			else
				return cur->right;
		}
		else//右孩子不存在，下一个结点直接看父节点
		{
			if (cur->next)//如果父节点存在
			{
				if (cur->next->left == cur)//我是父节点的左孩子，直接返回父节点
				{
					return cur->next;
				}
				else if (cur->next->right == cur && cur->next->next->left == cur->next)//我是父节点的右孩子，循环判断我的父节点是不是爷爷结点的左孩子，以及爷爷结点有没有右孩子
				{
					TreeLinkNode* dada = cur->next->next;
					for (; dada->next; dada = dada->next)
					{
						if (dada->right)
							break;
					}
					return dada;

				}
				else if (cur->next->right == cur && cur->next->next->right == cur->next)
				{
					return nullptr;
				}
			}
			else//如果父节点不存在
			{
				return nullptr;
			}
		}
		return nullptr;
	}
};

int main()
{


	return 0;
}