#include <iostream>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;
		ListNode* cur = pHead->next;
		ListNode* pro = pHead;
		if (cur->val == cur->next->val)
		{
			while ((cur->next != nullptr) && (cur->val == cur->next->val))
			{
				cur = cur->next;
			}
			pro->next = cur->next;
		}
		if (cur->val != cur->next->val)
		{
			cur = cur->next;
			pHead->next =  deleteDuplication(cur);
		}
		return pHead;
	}
};

int main()
{


	return 0;
}