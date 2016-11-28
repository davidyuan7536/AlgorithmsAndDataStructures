#include "leetcode.h"


TreeNode * process(TreeNode * head, TreeNode* root){

	while (head->right != nullptr && head->right != root){
		head = head->right;
	}

	return head;
}
void Solution::recoverTree(TreeNode* root){

	if (root == nullptr)
		return;

	TreeNode * prev = new TreeNode(INT_MIN);

	TreeNode * first = nullptr;
	TreeNode * second = nullptr;

	TreeNode * currentRoot = nullptr;

	while (root != nullptr){

		if (root->left){
			TreeNode * predecessor = process(root->left, root);
			if (predecessor->right == nullptr){
				predecessor->right = root;
				root = root->left;
			}
			else{
				predecessor->right = nullptr;
				cout << root->val << " ";
				if (first == nullptr && prev->val > root->val){
					first = prev;
					second = root;
				}
				else if (first != nullptr && prev->val > root->val){
					second = root;
				}
				prev = root;
				root = root->right;
			}
		}
		else{
			cout << root->val << " ";
			if (first == nullptr && prev->val > root->val){
				first = prev; 
				second = root;
			}
			else if (first != nullptr && prev->val > root->val){
				second = root; 
			}
			prev = root; 
			root = root->right;
		}
	
	}
	
	int temp = first->val;
	first->val = second->val;
	second->val = temp;

}