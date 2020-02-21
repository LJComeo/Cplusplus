#include <iostream>
using namespace std;


struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {}
};
class Solution
{
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;
		ListNode* NewHead = nullptr;

		if (pHead1->val < pHead2->val)
		{
			NewHead = pHead1;
			NewHead->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			NewHead = pHead2;
			NewHead->next = Merge(pHead2->next, pHead1);
		}
		return NewHead;
	}
};


int main()
{



	return 0;
}