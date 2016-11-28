#include "leetcode.h"

void Solution::setZeroes(vector<vector<int>>& matrix){

	vector<int> rows;
	vector<int> cols;

	int n = matrix.size();
	int m = matrix[0].size();

	for (int x = 0; x < n; x++){
		for (int y = 0; y < m; y++){

			if (matrix[x][y] == 0){
				rows.push_back(x);
				cols.push_back(y);
			}

		}
	}

	for (auto it : rows){
		for (int x = 0; x < m; x++){
			matrix[it][x] = 0;
		}
	}

	for (auto it : cols){
		for (int x = 0; x < n; x++){

			matrix[x][it] = 0;
		}
	}
}