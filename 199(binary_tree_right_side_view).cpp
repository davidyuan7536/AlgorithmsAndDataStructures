#include "leetcode.h"

void helper(TreeNode* root, vector<int> &ret){
	if (root == nullptr){
		return;
	}
	
	ret.push_back(root->val);
	if (root->right){
		helper(root->right, ret);
	}
	else if (root->left){
		helper(root->left, ret);
	}

}

vector<int> Solution::rightSideView(TreeNode* root){

	if (root == nullptr){
		return vector<int>{};
	}

	vector<int> ret;
	queue<TreeNode*> a;
	queue<TreeNode*> b;

	a.push(root);
	while (!a.empty() || !b.empty()){

		bool first = true;
		while (!a.empty()){
			TreeNode * temp = a.front();
			if (first){
				ret.push_back(temp->val);
				first = false;
			}
			if (temp->right){
				b.push(temp->right);
			}
			if (temp->left){
				b.push(temp->left);
			}
			a.pop();
		}

		first = true;
		while (!b.empty()){
			TreeNode * temp = b.front();
			if (first){
				ret.push_back(temp->val);
				first = false;
			}
			if (temp->right){
				a.push(temp->right);
			}
			if (temp->left){
				a.push(temp->left);
			}
			b.pop();
		}
	}

	return ret; 

}