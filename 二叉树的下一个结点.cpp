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
		if (cur->right)//�鿴�Һ����Ƿ����
		{
			if (cur->right->left)//������ڵĻ�����һ���������Һ��ӵ�������
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
		else//�Һ��Ӳ����ڣ���һ�����ֱ�ӿ����ڵ�
		{
			if (cur->next)//������ڵ����
			{
				if (cur->next->left == cur)//���Ǹ��ڵ�����ӣ�ֱ�ӷ��ظ��ڵ�
				{
					return cur->next;
				}
				else if (cur->next->right == cur && cur->next->next->left == cur->next)//���Ǹ��ڵ���Һ��ӣ�ѭ���ж��ҵĸ��ڵ��ǲ���үү�������ӣ��Լ�үү�����û���Һ���
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
			else//������ڵ㲻����
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