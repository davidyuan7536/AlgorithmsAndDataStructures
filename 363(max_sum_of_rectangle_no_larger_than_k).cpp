#include "leetcode.h"

struct compare{
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
		return a.first < b.first;
	}
};

int processRow(vector<int> &dp, int &left, int &right, int k){

	set<pair<int,int>> cumset;
	cumset.insert(make_pair(0,0));
	int best = INT_MIN, cum = 0;
	for (int i = 0; i<dp.size(); i++)
	{
		cum += dp[i];
		set<pair<int, int>>::iterator sit = lower_bound(cumset.begin(), cumset.end(), make_pair(cum - k, i), compare());
		if (sit != cumset.end() && best < cum - sit->first){
			best = cum - sit->first;
			left = sit->second + 1;
			right = i; 
		}
		cumset.insert(make_pair(cum, i));
	}

	return best;
}

int processRow2(vector<int> &dp, int k){

	set<int> cumset;
	cumset.insert(0);
	int best = INT_MIN, cum = 0;
	for (int i = 0; i<dp.size(); i++)
	{
		cum += dp[i];
		set<int>::iterator sit = cumset.lower_bound(cum-k);
		if (sit != cumset.end() && best < cum - *sit){
			best = cum - *sit;
		}
		cumset.insert(cum);
	}
	return best;
}

int Solution::maxSumSubmatrix(vector<vector<int>>& matrix, int k){

	if (matrix.empty()){
		return 0;
	}

	int bestSoFar = INT_MIN;
	
	for (int i = 0; i < matrix.size(); i++){
		vector<int> row(matrix[i].size(), 0);
		for (int j = i; j < matrix.size(); j++){
			for (int k = 0; k < matrix[j].size(); k++){
				row[k] += matrix[j][k];
			}
			
			int ret = processRow2(row, k);
			if (ret == k){
				return k;
			}
			else{
				if (bestSoFar < ret){
					bestSoFar = ret;
				}
			}

		}
	}
	return bestSoFar;

}