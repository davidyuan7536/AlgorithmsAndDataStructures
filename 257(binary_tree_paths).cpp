#include "leetcode.h"

void binaryTreePathsHelper(vector<string> &ret, vector<int> &cur, TreeNode * head){
	if (head == nullptr){
		return;
	}
	cur.push_back(head->val);
	if (head->left == nullptr && head->right == nullptr){
		string temp = "";
		for (int i = 0; i < cur.size(); i++){
			temp += to_string(cur[i]);
			temp.append("->");
		}
		temp.pop_back();
		temp.pop_back();
		ret.push_back(temp);
		return;
	}
	binaryTreePathsHelper(ret, cur, head->left);
	binaryTreePathsHelper(ret, cur, head->right);
	cur.pop_back();
}

vector<string> Solution::binaryTreePaths(TreeNode* root){
	vector<string> ret;
	vector<int> cur;
	binaryTreePathsHelper(ret, cur, root);
	return ret; 
}