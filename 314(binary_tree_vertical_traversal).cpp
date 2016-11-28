#include "leetcode.h"

void verticalOrderHelper(map<int, vector<int>> &m_map, TreeNode * root, int index){
	if (root == nullptr){
		return;
	}
	m_map[index].push_back(root->val);
	verticalOrderHelper(m_map, root->left, index - 1);
	verticalOrderHelper(m_map, root->right, index + 1);
}

void verticalOrderHelper2(map<int, vector<int>> &m_map, TreeNode * root){

	if (root == nullptr){
		return;
	}
	queue<pair<TreeNode*, int>> m_queue;
	m_queue.push(make_pair(root, 0));
	while (!m_queue.empty()){
		pair<TreeNode *, int> front = m_queue.front();
		m_queue.pop();
		m_map[front.second].push_back(front.first->val);
		if (front.first->left)
			m_queue.push(make_pair(front.first->left, front.second - 1));
		if (front.first->right)
			m_queue.push(make_pair(front.first->right, front.second + 1));
	}

}

vector<vector<int>> Solution::verticalOrder(TreeNode* root){
	map<int, vector<int>> m_map;
	vector<vector<int>> ret;
	verticalOrderHelper2(m_map, root);
	for (auto it : m_map){
		ret.push_back(it.second);
	}

	return ret; 
}