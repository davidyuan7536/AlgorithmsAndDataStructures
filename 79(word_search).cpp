#include "leetcode.h"



bool existHelper(vector<vector<char>> &board, vector<vector<bool>> &used, string word, int x, int y, int n){


	if (n >= word.length()){
		return true;
	}
	if (x < 0 || x >= board.size()){
		return false;
	}
	if (y < 0 || y >= board[0].size()){
		return false;
	}
	if (board[x][y] == word[n] && !used[x][y]){
		used[x][y] = true;
		if (!(existHelper(board, used, word, x + 1, y, n + 1) || existHelper(board, used, word, x - 1, y, n + 1) ||
			existHelper(board, used, word, x, y + 1, n + 1) || existHelper(board, used, word, x, y - 1, n + 1))){
			used[x][y] = false;
			return false;
		}
		else{
			return true;
		}
	}
	else{
		return false;
	}


}


bool Solution::exist(vector<vector<char>>& board, string word){

	if (board.empty()){
		return false;
	}
	if (word.length() > board.size() * board[0].size()){
		return false;
	}

	vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
	for (int x = 0; x < board.size(); x++){
		for (int y = 0; y < board[0].size(); y++){
			if (board[x][y] == word[0]){
				if (existHelper(board, used, word, x, y, 0)){
					return true;
				}
			}

		}
	}
	return false;
}