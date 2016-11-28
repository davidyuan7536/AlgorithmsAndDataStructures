#include "leetcode.h"

vector<int> Solution::findMinHeightTrees(int n, vector<pair<int, int>>& edges){

	unordered_map<int, unordered_set<int>> m_map;
	for (int i = 0; i < edges.size(); i++){
		m_map[edges[i].first].insert(edges[i].second);
		m_map[edges[i].second].insert(edges[i].first);
	}

	unordered_set<int> leaves;
	for (auto it : m_map){
		if (it.second.size() == 1){
			leaves.insert(it.first);
		}
	}

	while (n > 2){
		n -= leaves.size();
		unordered_set<int> newLeaves;
		for (auto it : leaves){
			int nextVal = 0;
			for (auto next : m_map[it]){
				nextVal = next;
			}
			m_map[nextVal].erase(it);
			if (m_map[nextVal].size() == 1){
				newLeaves.insert(nextVal);
			}
		}
		leaves = newLeaves;
	}

	vector<int> ret;
	for (auto it : leaves){
		ret.push_back(it);
	}
	return ret;
}