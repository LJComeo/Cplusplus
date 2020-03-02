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
这个问题是化难为易的题型，复制这种链表我们需要借用链表的性质，以及这道题可以分为以下三步
1.每个结点进行复制，然后挂到原来结点的next位置
2.新的节点的random，等于原来结点的random的next
3.链表拆分
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