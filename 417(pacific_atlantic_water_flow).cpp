#include "leetcode.h"

struct hasher{

	size_t operator()(const pair<int, int> &a) const{
		return hash<int>()(a.first) ^ hash<int>()(a.second);
	}
};


bool bfs(vector<int> &directions, vector<vector<int>>& matrix, unordered_map<pair<int, int>, pair<bool, bool>, hasher> &m_map, int x, int y){

	bool p = false, a = false;
	vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
	queue<pair<int, int>> m_queue;
	m_queue.push(make_pair(x, y));
	while (!m_queue.empty()){
		pair<int, int> front = m_queue.front();
		visited[front.first][front.second] = true;
		m_queue.pop();

		if (m_map.count(front)){
			if (m_map[front].first && m_map[front].second){
				m_map[make_pair(x, y)] = make_pair(true, true);
				return true;
			}
			if (m_map[front].first){
				p = true;
			}
			if (m_map[front].second){
				a = true;
			}
			continue;
		}

		for (int i = 0; i < 4; i++){
			int newX = front.first + directions[i];
			int newY = front.second + directions[i + 1];
			if (newX < 0 || newY < 0){
				p = true;
				continue;
			}
			else if (newX >= matrix.size() || newY >= matrix[0].size()){
				a = true;
				continue;
			}
			else if (matrix[front.first][front.second] > matrix[newX][newY] && !visited[newX][newY]){
				m_queue.push(make_pair(newX, newY));
			}
			if (a && p){
				m_map[make_pair(x, y)] = make_pair(true, true);
				return true;
			}
		}

	}
	m_map[make_pair(x, y)] = make_pair(p, a);
	return false;
}



vector<pair<int, int>> Solution::pacificAtlantic(vector<vector<int>>& matrix) {

	
	vector<int> directions{ 0, -1, 0, 1, 0 };
	vector<pair<int, int>> ret;
	if (matrix.empty() || matrix[0].empty()){
		return ret;
	}
	unordered_map<pair<int, int>, pair<bool, bool>, hasher> m_map;
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix[0].size(); j++){
			if (bfs(directions, matrix, m_map, i, j)){
				ret.push_back(make_pair(i, j));
			}
		}
	}
	return ret;

}