#include "leetcode.h"

int Solution::numIslands(vector<vector<char>>& grid){

	if (grid.empty()){
		return 0;
	}

	int m = grid.size();
	int n = grid[0].size();

	int counter = 0;

	vector<int> dir{ 0, 1, 0, -1, 0 };

	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (grid[i][j] == '1'){
				counter++;
				queue<pair<int, int>> myQ;
				myQ.push(make_pair(i, j));
				while (!myQ.empty()){
					
					pair<int, int> top = myQ.front();
					myQ.pop();

					grid[top.first][top.second] = '0';

					for (int k = 0; k < 4; k++){
						int x = top.first + dir[k];
						int y = top.second + dir[k + 1];
						if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1'){
							myQ.push(make_pair(x, y));
						}
					}
				}
			}
		}
	}
	return counter;
}