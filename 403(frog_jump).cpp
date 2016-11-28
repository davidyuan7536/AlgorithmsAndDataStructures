#include "leetcode.h"

bool Solution::canCross(vector<int>& stones){

	if (stones.size() <= 1){
		return true;
	}
	if (stones[1] != 1){
		return false;
	}
	if (stones.size() == 2){
		return true;
	}


	map<int, unordered_set<int>> indexValues;
	for (int i = 0; i < stones.size()-1; i++){
		indexValues.insert(make_pair(stones[i], unordered_set<int>{}));

	}

	indexValues[0].insert(1);
	indexValues[1].insert(1);
	indexValues[1].insert(2);
	
	for (auto it = ++indexValues.begin(); it != indexValues.end(); it++){

		for (auto setIt : it->second){

			if (it->first + setIt == stones.back()){
				return true;
			}
			if (indexValues.find(it->first + setIt) != indexValues.end()){

				for (int i = 1; i >= -1; i--){
					if (setIt + i > 0)
						indexValues[it->first + setIt].insert(setIt + i);
				}
			}

		}
	}
		
	return false; 

	/*
	if (stones.size() <= 1){
		return true;
	}

	vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), 0));
	unordered_map<int, int> indexValue;

	if (stones[1] != 1){
		return false;
	}
	if (stones.size() == 2){
		return true;
	}

	dp[0][1] = 1;

	for (int i = 0; i < stones.size(); i++){
		dp[i][i] = 1;
		indexValue.insert(make_pair(stones[i], i));
	}


	for (int i = 1; i < stones.size(); i++){
		for (int j = i+1; j < stones.size(); j++){
			int diff = stones[j] - stones[i];
			for (int d = -1; d <= 1; d++){
				if(stones[i] - (diff - d) >= 0 && diff - d != 0){
					int val = stones[i] - (diff - d);
					if (indexValue.find(val) == indexValue.end()){
						continue;
					}
					else{
						if (dp[indexValue[val]][i] == 1){
							dp[i][j] = 1;
							if (j == stones.size() - 1){
								return true;
							}
							break;
						}
					}
				}
			}
		}
	}
	return false;

	*/
}