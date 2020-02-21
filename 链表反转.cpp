#include <iostream>
using namespace std;


struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};
class Solution //Á´±í·´×ª
{
public:
	ListNode* ReverseList(ListNode* pHead)
	{
		if (!pHead)
		{
			return nullptr;
		}
		ListNode* cur = pHead;
		ListNode* tmp = pHead->next;
		cur->next = nullptr;
		while (tmp)
		{
			pHead = tmp;
			tmp = tmp->next;
			pHead->next = cur;
			cur = pHead;
		}
		return cur;
	}
};

