#include "leetcode.h";



void dfs(pair<int, int> &building, vector<vector<int>> &grid, vector<vector<int>> &distance){

	vector<pair<int, int>> direction{ make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1) };
	vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));
	queue<pair<int, int>> visitQueue;
	visitQueue.push(building);
	visited[building.first][building.second] = 0; 

	while (!visitQueue.empty()){

		pair<int, int> front = visitQueue.front();
		visitQueue.pop();
 

		for (int i = 0; i < direction.size(); i++){
			int x = front.first + direction[i].first;
			int y = front.second + direction[i].second;
			if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && !(grid[x][y] == 2 || grid[x][y] == 1) && visited[x][y] < 0){
				visitQueue.push(make_pair(x, y));
				visited[x][y] = 1 + visited[front.first][front.second];
			}

		}
	}

	for (int i = 0; i < distance.size(); i++){
		for (int j = 0; j < distance[0].size(); j++){
			distance[i][j] += (visited[i][j]);
		}
	}
}

int Solution::shortestDistance(vector<vector<int>>& grid){

	if (grid.empty())
		return -1;

	int n = grid.size();
	int m = grid[0].size();

	vector<vector<int>> distance(n, vector<int>(m, 0));
	vector<pair<int, int>> buildings;

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] == 1){
				buildings.push_back(make_pair(i, j));
			}
		}
	}
	
	for (int i = 0; i < buildings.size(); i++){
		dfs(buildings[i], grid, distance);
	}

	/*
	for (auto it : distance){
		for (auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
	}
	*/

	int ret = INT_MAX;
	for (int i = 0; i < distance.size(); i++){
		for (int j = 0; j < distance[0].size(); j++){
			cout << distance[i][j] << " ";
			if (distance[i][j] < 0){
				continue; 
			}
			ret = min(ret, distance[i][j]);
		}
		cout << endl;
	}

	return ret;
}