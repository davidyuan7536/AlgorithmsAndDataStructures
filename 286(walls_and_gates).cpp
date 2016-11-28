#include "leetcode.h"

void bfs(vector<vector<int>> &rooms, pair<int, int> index){

	vector<vector<int>> visited(rooms.size(), vector<int>(rooms[0].size(), 0));

	vector<int> directions{0, 1, 0, -1, 0};
	queue<pair<int, int>> myQ;
	myQ.push(index);
	while (!myQ.empty()){

		pair<int, int> top = myQ.front();
		myQ.pop();
		visited[top.first][top.second] = 1;

		for (int i = 0; i < 4; i++){
			int x = top.first + directions[i];
			int y = top.second + directions[i + 1];
			if (x >= 0 && x < rooms.size() && y >= 0 && y < rooms[0].size() && rooms[x][y] != -1 && rooms[x][y] != 0 && visited[x][y] == 0){
				myQ.push(make_pair(x, y));
				rooms[x][y] = min(1 + rooms[top.first][top.second], rooms[x][y]);
			}
		}
	}

}

void Solution::wallsAndGates(vector<vector<int>>& rooms){

	int m = rooms.size();
	int n = rooms[0].size();

	if (m == 0 || n == 0){
		return;
	}

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (rooms[i][j] == 0){
				bfs(rooms, make_pair(i, j));
			}
		}
	}

}