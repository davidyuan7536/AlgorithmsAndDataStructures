#include "leetcode.h"



TreeNode * getLeftMost(TreeNode* root){
	
	while (root->left){
		root = root->left;
	}
	return root;
}

TreeNode* Solution::inorderSuccessor(TreeNode* root, TreeNode* p){

	stack<TreeNode*> parentStack;
	TreeNode * cur = root;
	while (cur != p && cur != nullptr){
		parentStack.push(cur);
		
		if (p->val > cur->val){
			cur = cur->right;
		}
		else if (p->val < cur->val){
			cur = cur->left;
		}
	}

	if (cur == nullptr){
		return nullptr;
	}

	if (cur->right){
		return getLeftMost(cur->right);
	}
	else{
		while (!parentStack.empty()){
			TreeNode * top = parentStack.top();
			parentStack.pop();
			if (top->left == cur){
				return top;
			}
			else{
				cur = top;
			}
		}
	}

	return nullptr;

}