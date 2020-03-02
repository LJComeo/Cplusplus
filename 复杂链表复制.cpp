#include<iostream>
using namespace std;


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL) {
	}
};

/*
��������ǻ���Ϊ�׵����ͣ�������������������Ҫ������������ʣ��Լ��������Է�Ϊ��������
1.ÿ�������и��ƣ�Ȼ��ҵ�ԭ������nextλ��
2.�µĽڵ��random������ԭ������random��next
3.������
*/


class Solution
{
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		RandomListNode* cur = pHead;
		while (cur)
		{
			RandomListNode* tmp = new RandomListNode(cur->label);
			tmp->next = cur->next;
			cur->next = tmp;
			cur = tmp->next;
		}
		cur = pHead;
		RandomListNode* tmp = cur->next;
		while (1)
		{
			if (cur->random)
				tmp->random = cur->random->next;
			cur = tmp->next;
			if (cur == nullptr)
				break;
			tmp = cur->next;
		}
		RandomListNode* ret = pHead->next;
		cur = pHead;
		RandomListNode* cp;
		while (cur->next)
		{
			cp = cur->next;
			cur->next = cp->next;
			cur = cp;
		}
		return ret;
	}
};