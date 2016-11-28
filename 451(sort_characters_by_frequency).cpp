#include "leetcode.h"

struct PairCompare{
	bool operator()(const pair<int, char> &a, const pair<int, char> &b)const{
		return a.first < b.first;
	}
};

string Solution::frequencySort(string s){

	unordered_map<char, int> m_map;
	for (int i = 0; i < s.length(); i++){
		m_map[s[i]]++;
	}
	
	priority_queue<pair<int, char>, vector<pair<int, char>>, PairCompare> m_queue;
	for (auto it : m_map){
		m_queue.push(make_pair(it.second, it.first));
	}

	string ret = "";
	while (!m_queue.empty()){
		for (int i = 0; i < m_queue.top().first; i++){
			ret += m_queue.top().second;
		}
		m_queue.pop(); 
	}

	return ret;

}