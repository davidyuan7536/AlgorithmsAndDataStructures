#include "leetcode.h"

class ValidTreeDisjointSet{

	struct DJNode{
		DJNode * parent;
		int rank;
	};
	unordered_map<int, DJNode*> m_map;
	int num;

public:
	
	ValidTreeDisjointSet(){
		num = 0;
	}

	void newNode(int val){
		DJNode* temp = new DJNode;
		temp->parent = temp;
		temp->rank = 0;
		m_map[val] = temp;
		num++;
	}

	bool join(int a, int b){

		DJNode * parent1 = findParent(a);
		DJNode * parent2 = findParent(b);
		if (parent1 == parent2 || parent1 == nullptr || parent2 == nullptr){
			return true;
		}

		if (parent1->rank > parent2->rank){
			parent2->parent = parent1;
		}
		else if (parent1->rank < parent2->rank){
			parent1->parent = parent2;
		}
		else{
			parent1->rank++;
			parent2->parent = parent1;
		}
		num--;
		return false;
	}

	DJNode * findParent(int a){
		if (m_map.find(a) == m_map.end()){
			return nullptr;
		}
		return findParent(m_map[a]);
	}

	DJNode * findParent(DJNode * a){
		DJNode * parent = a->parent;
		if (parent == a){
			return a;
		}
		a->parent = findParent(parent);
		return a->parent;
	}
	int number(){
		return num;
	}
};


bool Solution::validTree(int n, vector<pair<int, int>>& edges){

	if (edges.size() != n - 1){
		return false;
	}

	ValidTreeDisjointSet dj;
	for (int i = 0; i < edges.size(); i++){
		if (dj.findParent(edges[i].first) == nullptr){
			dj.newNode(edges[i].first);
		}
		if (dj.findParent(edges[i].second) == nullptr){
			dj.newNode(edges[i].second);
		}
		if (dj.join(edges[i].first, edges[i].second)){
			return false;
		}
	}
	if (edges.empty())
		return true;
	return dj.number() == 1 ? true : false;
	
}