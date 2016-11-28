#include "leetcode.h"

void findLaddersDFS(string endWord, unordered_set<string> &wordList, unordered_map<string, unordered_set<string>>& m_map, vector<string> m_queue, unordered_set<string> &visited){

	vector<string> new_queue;
	bool foundEnd = false;
	for (auto it : m_queue){

		for (int i = 0; i < it.length(); i++){
			for (int j = 0; j <= 26; j++){

				if (it[i] != 'a' + j){
					string temp = it;
					temp[i] = 'a' + j;
					if (wordList.count(temp) && !visited.count(temp)){
						m_map[it].insert(temp);
						if (temp != endWord)
							new_queue.push_back(temp);
						else
							foundEnd = true;
					}
				}

			}
		}

	}
	if (new_queue.empty()){
		return;
	}
	for (auto it : new_queue){
		visited.insert(it);
	}
	if (foundEnd){
		visited.insert(endWord);
	}
	findLaddersDFS(endWord, wordList, m_map, new_queue, visited);
}

void findLaddersHelper(vector<vector<string>> &ret, vector<string> &cur, string startword, string &endword, unordered_map<string, unordered_set<string>> m_map, unordered_set<string> &visited){

	if (startword == endword){
		cur.push_back(endword);
		ret.push_back(cur);
		cur.pop_back();
		return;
	}

	unordered_set<string> children = m_map[startword];
	cur.push_back(startword);
	visited.insert(startword);
	for (auto it : children){
		if (!visited.count(it))
			findLaddersHelper(ret, cur, it, endword, m_map, visited);
	}
	cur.pop_back();
	visited.erase(startword);

}

vector<vector<string>> Solution::findLadders(string beginWord, string endWord, unordered_set<string> &wordList){
	
	vector<vector<string>> ret;
	vector<string> cur;
	unordered_map<string, unordered_set<string>> m_map;
	unordered_set<string> visited;
	vector<string> m_queue;
	m_queue.push_back(beginWord);
	visited.insert(beginWord);
	wordList.insert(endWord);
	findLaddersDFS(endWord, wordList, m_map, m_queue, visited);
	visited.clear();
	findLaddersHelper(ret, cur, beginWord, endWord, m_map, visited);
	for (auto it : ret){
		for (auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
	}
	return ret;
}