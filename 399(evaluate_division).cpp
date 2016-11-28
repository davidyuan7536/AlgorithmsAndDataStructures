#include "leetcode.h"

class DisjointSet2{

	struct Node{
		string name;
		double val;
		int rank;
		Node * parent;
		unordered_map<string, Node*> children;
	};

	unordered_map<string, Node*> m_map;

public:

	void newNode(string name){
		if (m_map.find(name) != m_map.end()){
			return;
		}

		Node * temp = new Node();
		temp->val = 1;
		temp->rank = 0;
		temp->parent = temp;
		temp->children = unordered_map<string, Node*>();
		temp->name = name;
		m_map[name] = temp;
	}

	void propagateDown(Node* parent, double val){
		for (auto it: parent->children){
			it.second->val *= val;
			propagateDown(it.second, val);
		}
	}

	void joinNodes(string a, string b, double ratio){

		double multiplier1 = getMultiplier(a);
		double multiplier2 = getMultiplier(b);
		Node * parent1 = findParent(a);
		Node * parent2 = findParent(b);

		if (parent1 == parent2 || parent1 == nullptr || parent2 == nullptr){
			return;
		}
		
		if (parent1->rank == parent2->rank){
			parent1->rank++;
			parent1->children.insert(make_pair(parent2->name, parent2));
			parent2->parent = parent1;
			parent2->val = parent2->val * (multiplier1 * ratio / multiplier2);
			propagateDown(parent2, parent2->val);
			return;
		}

		if (parent2->rank > parent1->rank){
			Node * temp = parent1;
			parent1 = parent2;
			parent2 = temp;

			ratio = 1 / ratio;
			parent1->children.insert(make_pair(parent2->name, parent2));
			parent2->parent = parent1;
			parent2->val = parent2->val * (multiplier2 * ratio / multiplier1);
			propagateDown(parent2, parent2->val);
		}
		else{
			parent1->children.insert(make_pair(parent2->name, parent2));
			parent2->parent = parent1;
			parent2->val = parent2->val * (multiplier1 * ratio / multiplier2);
			propagateDown(parent2, parent2->val);
		}

	}


	double getMultiplier(string name){
		return m_map[name]->val;
	}

	Node * findParent(string name){
		if (m_map.find(name) == m_map.end()){
			return nullptr;
		}
		vector<pair<string, Node*>> newChildren;
		
		return findParent(m_map[name], newChildren);
	}


	Node * findParent(Node * child, vector<pair<string, Node*>> &newChildren){

		Node * parent = child->parent;
		if (parent == child){

			for (int i = 0; i < newChildren.size(); i++){
				child->children.insert(make_pair(newChildren[i].first, newChildren[i].second));
			}
			return child;
		}

		newChildren.push_back(make_pair(child->name, child));
		parent->children.erase(child->name);
		child->parent = findParent(parent, newChildren);
		return child->parent;
	}

};



vector<double> Solution::calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries){

	DisjointSet2 dj;

	for (int i = 0; i < equations.size(); i++){
		dj.newNode(equations[i].first);
		dj.newNode(equations[i].second);
		dj.joinNodes(equations[i].first, equations[i].second, values[i]);
	}

	vector<double> ret;
	for (int i = 0; i < queries.size(); i++){

		
		if (dj.findParent(queries[i].first) != dj.findParent(queries[i].second)){
			ret.push_back(-1);
			continue;
		}
		if (dj.findParent(queries[i].first) == nullptr){
			ret.push_back(-1);
			continue;
		}
		if(dj.findParent(queries[i].second) == nullptr){
			ret.push_back(-1);
			continue;
		}
		double a = dj.getMultiplier(queries[i].first);
		double b = dj.getMultiplier(queries[i].second);

		ret.push_back(b / a);
	}

	return ret; 
}