#include "leetcode.h"

bool validConnection(vector<vector<int>>&grid, pair<int,int> a, pair<int,int>b){

	if ((abs(a.first - b.first) == 0 && abs(a.second - b.second) == 1) || (abs(a.first - b.first) == 1 && abs(a.second - b.second) == 0) || (abs(a.first - b.first) == 1 && abs(a.second - b.second) == 1)){
		return true;
	}

	if ((abs(a.first - b.first) == 2 && abs(a.second - b.second) == 0)){

		return grid[1][a.second] == 1 ? true : false; 
	}

	if ((abs(a.first - b.first) == 0 && abs(a.second - b.second) == 2)){

		return grid[a.first][1] == 1 ? true : false;
	}

	if ((abs(a.first - b.first) == 2 && abs(a.second - b.second) == 1) || (abs(a.first - b.first) == 1 && abs(a.second - b.second) == 2)){
		return true;
	}

	if ((abs(a.first - b.first) == 2 && abs(a.second - b.second) == 2)){
		return grid[1][1] == 1 ? true : false;
	}

	return false;
}

void helper(int min, int max, vector<vector<int>> &grid, int&ret, int x, int y){

	if (min <= 0){
		ret++;
	}
	if (max == 0){
		return;
	}

	grid[x][y] = 1;

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			if (grid[i][j] == 1 || (i == x && j == y)){
				continue;
			}

			if (validConnection(grid, make_pair(x,y), make_pair(i,j))){
		
				helper(min-1, max-1, grid, ret, i, j);
			
			}
		}
	}
	grid[x][y] = 0;

}

int Solution::numberOfPatterns(int m, int n){

	int ret = 0;
	vector<vector<int>> grid(3, vector<int>(3, 0));
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			helper(m-1, n-1, grid, ret, i, j);
		}
	}
	
	return ret;

}