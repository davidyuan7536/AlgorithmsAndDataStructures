#include "leetcode.h"

void buildTreeHelper(vector<int> &preorder, vector<int>& inorder, TreeNode *& curNode, int cur, int left, int right){
	
	curNode = new TreeNode(preorder[cur]);
	if (left == right || cur >= preorder.size()){
		return;
	}
	int pos = find(inorder.begin(), inorder.begin()+right, preorder[cur]) - inorder.begin();
	if (pos != left){
		buildTreeHelper(preorder, inorder, curNode->left, cur+1, left, pos-1);
	}
	else{
		buildTreeHelper(preorder, inorder, curNode->right, cur+1, pos+1, right);
	}
}


TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder){

	TreeNode * head = nullptr;
	buildTreeHelper(preorder, inorder, head, 0, 0, preorder.size() - 1);
	return head;
}