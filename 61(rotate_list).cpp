#include "leetcode.h"

ListNode* Solution::rotateRight(ListNode* head, int k){
	if (head == NULL || head->next == NULL || k == 0) return head;
	int len = 1;
	ListNode *tail = head;

	/* find the end of list */
	while (tail->next != NULL) {
		tail = tail->next;
		len++;
	}

	/* form a circle */
	tail->next = head;
	k = k % len;
	for (int i = 0; i < len - k; i++) {
		tail = tail->next;
	}
	head = tail->next;
	tail->next = NULL;
	return head;

}