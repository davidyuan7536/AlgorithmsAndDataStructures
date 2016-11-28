#include "leetcode.h"

template<typename T1, typename T2>
void merge(vector<pair<T1, T2>> &vec, int l, int m, int r){
	
	vector<pair<T1, T2>> retVec;
	int left = l, middle = m+1, right = r;
	while (left <= m && middle <= r){

		if (vec[left].first < vec[middle].first){
			retVec.push_back(vec[left]);
			left++;
		}
		else if (vec[left].first > vec[middle].first){
			retVec.push_back(vec[middle]);
			middle++;
		}
		else{

			if (vec[left].second < vec[middle].second){
				retVec.push_back(vec[left]);
				left++;
			}
			else{
				retVec.push_back(vec[middle]);
				middle++;
			}

		}

	}

	while (left <= m){
		retVec.push_back(vec[left]);
		left++;
	}

	while (middle <= r){
		retVec.push_back(vec[middle]);
		middle++;
	}
	left = l;
	for (int i = 0; i < retVec.size(); i++){
		vec[left + i] = retVec[i];
	}
}

template<typename T1, typename T2>
void mergeSort(vector<pair<T1, T2>> &vec, int l, int r){

	if (r <= l){
		return;
	}
	
	int mid = l + (r - l) / 2;
	mergeSort(vec, l, mid);
	mergeSort(vec, mid + 1, r);
	merge(vec, l, mid, r);
}


int Solution::maxEnvelopes(vector<pair<int, int>>& envelopes){

	if (envelopes.empty())
		return 0;

	mergeSort(envelopes, 0, envelopes.size() - 1);
	vector<int> dp(envelopes.size(), 1);

	int max = 1;
	for (int i = 1; i < envelopes.size(); i++){
		int maxVal = 1;
		for (int j = 0; j < i; j++){
			if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
				if (1 + dp[j] > maxVal){
					maxVal = 1 + dp[j];
				}
			}
		}
		dp[i] = maxVal;
		if (maxVal > max){
			max = maxVal;
		}
	}

	return max;
}