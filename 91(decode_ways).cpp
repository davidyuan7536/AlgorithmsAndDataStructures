#include "leetcode.h"

int Solution::numDecodings(string s){


	vector<int> dp(s.length(), 1);

	
	if (s == "" || s[0] == '0'){
		return 0;
	}

	for (int i = 1; i < s.length(); i++){
		if (s[i] == '0'){
			if (s[i - 1] != '1' && s[i-1] != '2'){
				return 0;
			}
			dp[i] = i >= 2 ? dp[i - 2] : 1;
		}
		else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] - '0' <= 6)){
			dp[i] = i >= 2 ? dp[i - 1] + dp[i - 2] : dp[i - 1] + 1;
		}
		else{
			dp[i] = dp[i - 1];
		}
	}
	
	return dp.back();
	

	/*
	vector<vector<int>> dp(s.length(), vector<int>(s.length, 1));
	
	for (int len = 2; len < s.length(); len++){

		for (int x = 0; x < s.length() - len; x++){

			int y = x + len - 1; 
			dp[x][y] = s[y - 1] == 1 || (s[y - 1] == 2 && s[y] - '0' <= 6) ? dp[x][y - 1] + dp[x][y - 1] : dp[x][y - 1];

		}
	}
	*/


}