#include "leetcode.h"

struct pqComparer{
	bool operator()(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)const{
		return a.first > b.first;
	}
};

int Solution::kthSmallest(vector<vector<int>>& matrix, int k){

	vector<vector<int>> visited(matrix.size(), vector<int>(matrix.size(), 0));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, pqComparer> m_queue;

	m_queue.push(make_pair(matrix[0][0], make_pair(0, 0))); 
	visited[0][0] = 1;
	while (true){
		pair<int, pair<int, int>> top = m_queue.top();
		
		m_queue.pop();
		k--;
		if (k == 0){
			return top.first;
		}
		if (top.second.first + 1 < matrix.size() && visited[top.second.first + 1][top.second.second] == 0){
			visited[top.second.first+1][top.second.second] = 1;
			m_queue.push(make_pair(matrix[top.second.first + 1][top.second.second], make_pair(top.second.first + 1, top.second.second)));
		}
		if (top.second.second + 1 < matrix.size() && visited[top.second.first][top.second.second + 1] == 0){
			visited[top.second.first][top.second.second+1] = 1;
			m_queue.push(make_pair(matrix[top.second.first][top.second.second + 1], make_pair(top.second.first, top.second.second + 1)));
		}
	}
	return 0; 
}