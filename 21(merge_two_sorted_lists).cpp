#include "leetcode.h"

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2){

	ListNode* head = new ListNode(0);
	ListNode* it = head;

	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			it->next = l1;
			it = l1;
			l1 = l1->next;
		}
		else
		{
			it->next = l2;
			it = l2;
			l2 = l2->next;
		}
	}

	if (l1)   it->next = l1;
	if (l2)   it->next = l2;

	it = head->next;
	delete head;

	return head->next;

}