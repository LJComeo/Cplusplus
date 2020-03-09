#include <iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};
class Solution {
public:
	int Length(ListNode* pHead)
	{
		int count = 0;
		if (pHead == nullptr)
			return 0;
		ListNode* cur = pHead;
		for (; cur; cur = cur->next)
		{
			count++;
		}
		return count;
	}
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr || pHead2 == nullptr)
			return nullptr;
		ListNode* cur = pHead1;
		ListNode* tmp = pHead2;
		int length1 = Length(pHead1);
		int length2 = Length(pHead2);
		int Distance =abs(length1 - length2);
		if (length1 < length2)
		{
			for (int i = 0; i < Distance; i++)
			{
				tmp = tmp->next;
			}
		}
		else if (length1 > length2)
		{
			for (int i = 0; i < Distance; i++)
			{
				cur = cur->next;
			}
		}
		
		for (; cur && tmp; cur = cur->next, tmp = tmp->next)
		{
			if (cur == tmp)
				return cur;
		}
		return nullptr;
	}
};

int main2()
{


	return 0;
}