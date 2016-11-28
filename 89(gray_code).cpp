#include "leetcode.h"

int grayCodeHelper(vector<int> grayCode){
	
	int counter = 0;
	int num = 0;
	while (!grayCode.empty()){
		num += grayCode.back() * pow(2, counter);
		counter++;
		grayCode.pop_back();
	}

	return num;
}

void grayCodeSequence(int n, vector<int> & temp, vector<vector<int>> &gc, int & counter){
	
	if (n == 0){
		counter++;
		gc.push_back(temp);
		return;
	}

	temp.push_back(0);
	grayCodeSequence(n - 1, temp, gc, counter);
	temp.pop_back();
	temp.push_back(1);
	grayCodeSequence(n - 1, temp, gc, counter);
	temp.pop_back();

}

vector<int> Solution::grayCode(int n){

	/*
	vector<vector<int>> gc;
	vector<int> temp;
	int counter = 0;
	grayCodeSequence(n, temp, gc, counter);
	
	vector<int> sol;
	for (int i = 0; i < gc.size(); i++){
		sol.push_back(grayCodeHelper(gc[i]));
	}
	return sol;
	*/

	vector<int> result(1, 0);
	for (int i = 0; i < n; i++) {
		int curCount = result.size();
		while (curCount) {
			curCount--;
			int curNum = result[curCount];
			curNum += (1 << i);
			result.push_back(curNum);
		}
	}
	return result;

}