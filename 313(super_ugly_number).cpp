#include "leetcode.h"

struct MinQueue{
	bool operator()(const int &a, const int &b)const{
		return a > b;
	}
};

int Solution::nthSuperUglyNumber(int n, vector<int>& primes){

	if (n < 1){
		return 0;
	}
	if (n == 1){
		return 1;
	}

	vector<int> index(primes.size(), 0);

	vector<int> dp(n + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= n; i++){

		int cur = INT_MAX;
		for (int j = 0; j < primes.size(); j++){
			cur = min(cur, primes[j] * dp[index[j]]);
		}
		dp[i] = cur;

		for (int j = 0; j < index.size(); j++){
			if (dp[i] == primes[j] * dp[index[j]])
				index[j]++; 
		}
	}

	return dp[n-1];
	
}