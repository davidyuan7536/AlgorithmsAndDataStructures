#include "leetcode.h"

bool binarySearch(vector<int> row, int target, int left, int right){

	if (right < left){
		return false;
	}
	
	int mid = left + (right - left) / 2; 
	if (row[mid] == target){
		return true;
	}
	else if (row[mid] > target){
		return binarySearch(row, target, left, mid - 1);
	}
	else{
		return binarySearch(row, target, mid + 1, right);
	}

}




bool Solution::searchMatrix(vector<vector<int>>& matrix, int target){

	int top = 0;
	int bot = matrix.size()-1;

	int end = matrix[0].size() - 1;


	if (bot == top){
		return binarySearch(matrix[0], target, 0, end);
	}

	while (top <= bot){

		int mid = top + (bot - top) / 2;
		if (matrix[mid][0] <= target && matrix[mid][end] >= target){
			return binarySearch(matrix[mid], target, 0, end);
		}
		else if(matrix[mid][0] > target){
			bot = mid - 1;
			continue;
		}
		else{
			top = mid + 1;
			continue;
		}

	}

	return false;
}