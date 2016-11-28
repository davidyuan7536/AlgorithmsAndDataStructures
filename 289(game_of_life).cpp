#include "leetcode.h"


int getSum(vector<vector<int>> &board, int x, int y){

	vector<pair<int, int>> directions{ { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 } };

	int sum = board[x][y];

	for (int i = 0; i < directions.size(); i++){

		int newX = x + directions[i].first;
		int newY = y + directions[i].second;

		if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size()){
			sum += board[newX][newY] & 1;
		}
	}

	return sum; 
}

void Solution::gameOfLife(vector<vector<int>>& board){

	if (board.size() <= 0)
		return;

	int n = board.size();
	int m = board[0].size(); 

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			
			int surroundSum = getSum(board, i, j);
			if (surroundSum == 3){
				board[i][j] = board[i][j] == 1 ? 3 : 2;
			}
			else if (surroundSum == 4){
				board[i][j] = board[i][j] == 1 ? 3 : 0;
			}
			else{
				board[i][j] = board[i][j] == 1 ? 2 : 0; 
			}
		}
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			board[i][j] = board[i][j] >> 1;
		}
	}

}