#include "leetcode.h"



void helper(TreeNode* root, int&current, int&maxRet){

	if (root == nullptr){
		return;
	}

	maxRet = max(maxRet, current);

	int cur = current;

	if (root->left){
		if (root->val == root->left->val - 1){
			current++;
			helper(root->left, current, maxRet);
		}
		else{
			current = 1;
			helper(root->left, current, maxRet);
		}
	}

	current = cur;
	if (root->right){
		if (root->val == root->right->val - 1){
			current++;
			helper(root->right, current, maxRet);
		}
		else{
			current = 1;
			helper(root->right, current, maxRet);
		}
	}
}

int Solution::longestConsecutive(TreeNode* root){
	
	if (root == nullptr){
		return 0;
	}
	int current = 1;
	int maxRet = 1;
	helper(root, current, maxRet);
	return maxRet; 
}