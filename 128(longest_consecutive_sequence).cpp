#include "leetcode.h"


class DJSet{
	
	struct DJNode{
		int child;
		DJNode * parent;
	};

	unordered_map<int, DJNode*> m_map;

	int m_longest;

public:

	DJSet(){
		m_longest = 0;
	}

	DJNode * newNode(int val){

		
		DJNode * temp = new DJNode();
		temp->child = 1;
		temp->parent = temp;
		m_longest = max(1, m_longest);
		m_map[val] = temp;
		return temp;
	}

	void joinNodes(int a, int b){

		DJNode * parentA = findParent(a);
		DJNode * parentB = findParent(b);
		if (parentA == parentB || parentA == nullptr || parentB == nullptr){
			return;
		}
		
		if (parentA->child > parentB->child){
			parentA->child += parentB->child;
			parentB->parent = parentA;
			
		}
		else if (parentB->child > parentA->child){
			parentB->child += parentA->child;
			parentA->parent = parentB;
		}
		else{
			parentA->child += parentB->child;
			parentB->parent = parentA;
		}

		m_longest = max(m_longest, parentA->child);
		m_longest = max(m_longest, parentB->child);
	}

	DJNode * findParent(int a){
		if (m_map.find(a) == m_map.end()){
			return nullptr;
		}
		else{
			return findParent(m_map[a]);
		}
	}

	DJNode * findParent(DJNode * a){

		DJNode * parent = a->parent;
		if (parent == a){
			return a;
		}
		else{
			a->parent = findParent(parent);
		}
		return a->parent; 
	}

	int longest(){
		return m_longest;
	}

};

int Solution::longestConsecutive(vector<int>& nums){

	DJSet myDJSet;

	for (int i = 0; i < nums.size(); i++){
		if (myDJSet.findParent(nums[i]) != nullptr){
			continue;
		}
		else{
			myDJSet.newNode(nums[i]);
			myDJSet.joinNodes(nums[i] + 1, nums[i]);
			myDJSet.joinNodes(nums[i] - 1, nums[i]);
		}
	}

	return myDJSet.longest();
}