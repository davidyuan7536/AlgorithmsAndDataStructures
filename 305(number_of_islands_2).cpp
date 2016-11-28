#include "leetcode.h"

class DisjointSet{

private:

	struct DJNode{
		DJNode * parent;
		pair<int, int> val; 
		int rank;
	};

	struct PairHash {
		template <typename T, typename U>
		std::size_t operator()(const std::pair<T, U> &x) const
		{
			return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
		}
	};

	unordered_map<pair<int, int>, DJNode*, PairHash> m_map;

	int numSets;

public:

	DisjointSet(){
		numSets = 0;
	}

	int numberOfSets(){
		return numSets;
	}

	void makeNode(pair<int, int> index){
		DJNode * temp = new DJNode();
		temp->parent = temp;
		temp->rank = 0;
		temp->val = index;
		m_map.insert(make_pair(index, temp));
		numSets++;
	}

	void join(pair<int, int> index1, pair<int, int> index2){

		if (m_map.find(index1) == m_map.end() || m_map.find(index2) == m_map.end()){
			return;
		}
		DJNode* parent1 = findParent(index1);
		DJNode* parent2 = findParent(index2);

		if (parent1 == parent2){
			return; 
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
		numSets--;
	}

	DJNode* findParent(pair<int, int> index){
		
		if (m_map.find(index) == m_map.end()){
			return nullptr;
		}

		DJNode * child = m_map[index];
		return findParent(child);
		
	}

	DJNode * findParent(DJNode * child){

		if (child->parent == child){
			return child;
		}
		else{
			child->parent = findParent(child->parent);
		}
		return child->parent;
	}

};


vector<int> Solution::numIslands2(int m, int n, vector<pair<int, int>>& positions){

	DisjointSet djs;
	vector<int> ret;
	for (int i = 0; i < positions.size(); i++){

		if (positions[i].first >= 0 && positions[i].first < m && positions[i].second >= 0 && positions[i].second < n){
			djs.makeNode(positions[i]);
			int x = positions[i].first;
			int y = positions[i].second;
			if (x - 1 >= 0 && djs.findParent(make_pair(x-1, y)) != nullptr){
				djs.join(positions[i], make_pair(x - 1, y));
			}
			if (x + 1 < m && djs.findParent(make_pair(x + 1, y)) != nullptr){
				djs.join(positions[i], make_pair(x + 1, y));
			}
			if (y - 1 >= 0 && djs.findParent(make_pair(x, y-1)) != nullptr){
				djs.join(positions[i], make_pair(x, y-1));
			}
			if (y + 1 < n && djs.findParent(make_pair(x, y+1)) != nullptr){
				djs.join(positions[i], make_pair(x, y+1));
			}
		}
		ret.push_back(djs.numberOfSets());
	}
	return ret;
}