#include "leetcode.h"


ListNode* reverseList(ListNode* head){

	ListNode * prev = nullptr;
	ListNode * next = nullptr;
	ListNode * current = head;

	while (current != nullptr){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next; 
	}
	return prev; 
}


ListNode* Solution::plusOne(ListNode* head){

	if (head == nullptr){
		return new ListNode(1);
	}

	head = reverseList(head);
	ListNode * cur = head;
	int carry = 1;
	while (carry != 0){
		cur->val  = (cur->val + carry) % 10;
		carry = cur->val + carry >= 10 ? 1 : 0;
		if (cur->next == nullptr)
			break;
		cur = cur->next;
	}
	if (carry != 0){
		cur->next = new ListNode(1);
	}
	
	return reverseList(head);

}