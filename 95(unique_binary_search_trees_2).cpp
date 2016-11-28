#include "leetcode.h"


struct Hasher
{
	size_t operator()(const TreeNode* k) const
	{

		size_t hashNum = hash<int>()(k->val);
		stack<TreeNode*> tnStack;
		if (k->left != nullptr)
			tnStack.push(k->left);
		if (k->right != nullptr)
			tnStack.push(k->right);

		while (!tnStack.empty()){
			TreeNode * head = tnStack.top();
			hashNum ^= hash<int>()(head->val);
			tnStack.pop();
			if (head->left != nullptr)
				tnStack.push(head->left);
			if (head->right != nullptr)
				tnStack.push(head->right);

		}

		return hashNum;
	}
};

bool compareTrees(const TreeNode * head1, const TreeNode * head2){

	if (head1 == nullptr && head2 == nullptr){
		return true;
	}
	if (head1 == nullptr){
		return false;
	}
	if (head2 == nullptr){
		return false;
	}

	if (head1->val != head2->val){
		return false;
	}
	else{
		return compareTrees(head1->left, head2->left) && compareTrees(head1->right, head2->right);
	}
}


struct Comparer
{
	bool operator()(const TreeNode *a, const TreeNode *b) const
	{
		return compareTrees(a, b);
	}
};

TreeNode* insertTree(TreeNode * head, int n){

	if (head == nullptr){
		TreeNode *temp = new TreeNode(n);
		return temp;
	}
	
	if (n > head->val){
		head->right = insertTree(head->right, n);
	}
	else if (n < head->val){
		head->left = insertTree(head->left, n);
	}
	
	return head;
}


void generateTree(unordered_set<int> &mySet, vector<int> &myVec, unordered_set<TreeNode*, Hasher, Comparer> &treeVec, int n, int num){

	if (n == 0){

		TreeNode* head = nullptr;
		for (auto it : myVec){
			head = insertTree(head, it);
		}

		if (treeVec.find(head) == treeVec.end()){
			treeVec.insert(head);
		}
		return;
	}

	for (int i = 1; i <= num; i++){
		if (mySet.find(i) != mySet.end()){
			continue;
		}
		myVec.push_back(i);
		mySet.insert(i);
		generateTree(mySet, myVec, treeVec, n-1, num);
		myVec.pop_back();
		mySet.erase(i);
	}
}

vector<TreeNode*> Solution::generateTrees(int n){

	if (n == 0){
		return vector<TreeNode*>();
	}
	unordered_set<int> mySet;
	vector<int> myVec;
	unordered_set<TreeNode*, Hasher, Comparer> treeVec;
	generateTree(mySet, myVec, treeVec, n, n);
	vector<TreeNode*> retVec;
	for (auto it : treeVec){
		retVec.push_back(it);
	}

	return retVec;

}