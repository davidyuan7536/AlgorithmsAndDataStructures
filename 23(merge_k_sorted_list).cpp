#include "leetcode.h"

ListNode* myMerge(ListNode* a, ListNode* b) {
	if (!a) return b;
	if (!b) return a;
	if (a->val < b->val) {
		a->next = myMerge(a->next, b);
		return a;
	}
	else {
		b->next = myMerge(a, b->next);
		return b;
	}
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists){

	ListNode* prev = *lists.begin();
	ListNode* ret = nullptr;
	for (auto it = lists.begin()+1; it != lists.end(); it++){
		ret = myMerge(*it, prev);
		prev = *it;
	}
	return ret;
}

