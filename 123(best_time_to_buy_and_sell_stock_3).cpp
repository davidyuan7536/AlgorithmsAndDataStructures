#include "leetcode.h"

int Solution::maxProfit(vector<int>& prices){

	if (prices.size() <= 1) return 0;
	int *dpLeft = new int[prices.size() + 1]; dpLeft[0] = 0;
	int tmp = prices[0];
	for (int i = 1; i<prices.size(); i++){
		tmp = min(tmp, prices[i]);
		dpLeft[i] = max(dpLeft[i - 1], prices[i] - tmp);
	}
	int *dpRight = new int[prices.size()]; dpRight[prices.size() - 1] = 0;
	tmp = prices[prices.size() - 1];
	for (int i = prices.size() - 2; i >= 0; i--){
		tmp = max(tmp, prices[i]);
		dpRight[i] = max(dpRight[i + 1], tmp - prices[i]);
	}
	tmp = 0;
	for (int i = 0; i<prices.size() - 1; i++){
		tmp = max(tmp, dpLeft[i] + dpRight[i + 1]);
	}
	tmp = max(tmp, dpLeft[prices.size() - 1]);
	return tmp;

}