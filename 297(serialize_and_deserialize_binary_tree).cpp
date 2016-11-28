#include "leetcode.h"

 
string Codec2::serialize(TreeNode* root){

	string ret;
	queue<TreeNode*> m_queue;
	if (root == nullptr){
		ret += '#';
		return ret;
	}
	m_queue.push(root);

	while (!m_queue.empty()){
		TreeNode * top = m_queue.front();
		m_queue.pop();
		if (top == nullptr){
			ret += '#';
			ret += ',';
		}
		else{
			ret.append(to_string(top->val));
			ret += ',';
			m_queue.push(top->left);
			m_queue.push(top->right);
		}
	}
	return ret; 
}

TreeNode* Codec2::deserialize(string data){

	if (data.empty() || data[0] == '#'){
		return nullptr;
	}
	int prev = 0;
	int found = data.find(",");
	TreeNode * cur = new TreeNode(stoi(data.substr(prev, found-prev)));
	queue<TreeNode*> m_queue;
	m_queue.push(cur);
	while(found+1 < data.length()){
		TreeNode * front = m_queue.front(); 
		for (int i = 0; i < 2; i++){
			prev = found + 1;
			found = data.find(",", prev);
			if (data.substr(prev, found-prev) == "#"){
				continue;;
			}
			else{
				if (i == 0){
					TreeNode * leftChild = new TreeNode(stoi(data.substr(prev, found)));
					front->left = leftChild;
					m_queue.push(leftChild);
				}
				else{
					TreeNode * rightChild = new TreeNode(stoi(data.substr(prev, found)));
					front->right = rightChild;
					m_queue.push(rightChild);
				}
			}
		}
		m_queue.pop();
	}
	return cur; 
}