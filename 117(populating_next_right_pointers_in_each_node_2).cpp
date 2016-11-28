#include "leetcode.h"

void Solution::connect2(TreeLinkNode *root){
	if (root == nullptr){
		return;
	}

	TreeLinkNode * current = root;
	TreeLinkNode * prev = nullptr;
	TreeLinkNode * head = nullptr;

	while (current != nullptr){
		while (current != nullptr){
			if (current->left){
				if (prev != nullptr){
					prev->next = current->left;
				}
				else{
					head = current->left;
				}
				prev = current->left;

			}
			if (current->right){
				if (prev != nullptr){
					prev->next = current->right;
				}
				else{
					head = current->right;
				}
				prev = current->right;
			}
			current = current->next;
		}

		current = head;
		head = nullptr;
		prev = nullptr;

	}
}