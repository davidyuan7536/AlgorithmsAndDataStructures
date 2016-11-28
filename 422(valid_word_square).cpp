#include "leetcode.h"

bool Solution::validWordSquare(vector<string>& words){

	if (words.empty()){
		return true;
	}


	for (int i = 0; i < words.size(); i++){
		int len = words[i].length();
		if (words.size() < len){
			return false;
		}
		for (int j = 0; j < len; j++){
			if (words[j].length() < i || words[i][j] != words[j][i]){
				return false;
			}
		}
	}
	return true;
}