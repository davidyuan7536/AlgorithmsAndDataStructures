#include "leetcode.h"

int Solution::maxProfit2(vector<int>& prices){

	if (prices.size() <= 1){
		return 0;
	}

	vector<int> profitHere(prices.size(), 0);
	int maxSoFar = 0;

	profitHere[0] = 0;

	for (int i = 1; i < prices.size(); i++){

		for (int j = i - 1; j >= 0; j--){
			if (prices[i] > prices[j]){
				maxSoFar = max(maxSoFar, prices[i] - prices[j] + (j >= 3 ? profitHere[j - 2] : 0));
			}
			profitHere[i] = maxSoFar;
		}

	}

	return profitHere[prices.size() - 1];
}