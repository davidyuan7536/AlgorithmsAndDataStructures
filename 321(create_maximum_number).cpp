#include "leetcode.h"

void helper(vector<int> &ret, vector<int> &current, unordered_map<int, int> counter, vector<int> &a, vector<int> &b, int m, int n, int k){

	if (current.size() == k || (m >= a.size() && n >= b.size())){
		if (ret.empty()){
			ret = current;
		}
		else{
			for (int i = 0; i < current.size(); i++){
				if (ret[i] < current[i]){
					ret = current;
					break;
				}
				else if (ret[i] > current[i]){
					break;
				}
			}
		}
		return; 
	}
	
	if (m < a.size() && n < b.size() && a[m] > b[n]){
		if (counter[a[m]] > 0){
			current.push_back(a[m]);
			counter[a[m]]--;
			helper(ret, current, counter, a, b, m + 1, n, k);
			counter[a[m]]++;
			current.pop_back();
		}
		else
			helper(ret, current, counter, a, b, m + 1, n, k);
		
	}
	else if (m < a.size() && n < b.size() && a[m] < b[n]){
		if (counter[b[n]] > 0){
			current.push_back(b[n]);
			counter[b[n]]--;
			helper(ret, current, counter, a, b, m, n + 1, k);
			counter[b[n]]++;
			current.pop_back();
		}
		else
			helper(ret, current, counter, a, b, m, n + 1, k);
	}
	else if (m < a.size() && n < b.size() && a[m] == b[n]){
		if (counter[a[m]] > 0){
			current.push_back(a[m]);
			counter[a[m]]--;
			helper(ret, current, counter, a, b, m + 1, n, k);
			current.pop_back();
			current.push_back(b[n]);
			helper(ret, current, counter, a, b, m, n + 1, k);
			counter[a[m]]++;
			current.pop_back();
		}
		else{
			helper(ret, current, counter, a, b, m + 1, n, k);
			helper(ret, current, counter, a, b, m, n + 1, k);
		}
	}
	else if (m < a.size()){
		if (counter[a[m]] > 0){
			current.push_back(a[m]);
			counter[a[m]]--;
			helper(ret, current, counter, a, b, m + 1, n, k);
			counter[a[m]]++;
			current.pop_back();
		}
		else
			helper(ret, current, counter, a, b, m + 1, n, k);
	}
	else if (n < b.size()){
		if (counter[b[n]] > 0){
			current.push_back(b[n]);
			counter[b[n]]--;
			helper(ret, current, counter, a, b, m, n + 1, k);
			counter[b[n]]++;
			current.pop_back();
		}
		else
			helper(ret, current, counter, a, b, m, n + 1, k);
	}
}


vector<int> Solution::maxNumber(vector<int>& nums1, vector<int>& nums2, int k){

	vector<vector<vector<int>>> dp(nums1.size() + 1, vector<vector<int>>(nums2.size()+1, vector<int>()));

	for (int i = 0; i <= nums1.size(); i++){
		for (int j = 0; j <= nums2.size(); j++){

			if (i == 0 && j == 0){
				continue;
			}
			else if (i == 0){
				if (dp[i][j - 1].size() < k){
					dp[i][j] = dp[i][j - 1];
					dp[i][j].push_back(nums2[j-1]);
				}
				else{
					vector<int> temp;
					bool replacedSmaller = false;
					for (int k = 0; k < dp[i][j - 1].size(); k++){
						if (!replacedSmaller && dp[i][j - 1][k] < nums2[j - 1]){
							replacedSmaller = true;
							continue;
						}
						else{
							temp.push_back(dp[i][j - 1][k]);
						}
					}
					temp.push_back(nums2[j - 1]);
				}
			}
			else if (j == 0){
				if (dp[i-1][j].size() < k){
					dp[i][j] = dp[i-1][j];
					dp[i][j].push_back(nums1[i - 1]);
				}
				else{
					vector<int> temp;
					bool replacedSmaller = false;
					for (int k = 0; k < dp[i-1][j].size(); k++){
						if (!replacedSmaller && dp[i-1][j][k] < nums1[i - 1]){
							replacedSmaller = true;
							continue;
						}
						else{
							temp.push_back(dp[i-1][j][k]);
						}
					}
					temp.push_back(nums1[i - 1]);
				}
			}
			else{
				vector<int> cur;
				unordered_map<int, int> counter;
				for (int a = 0; a < i; a++){
					counter[nums1[a]]++;
				}
				for (int b = 0; b < j; b++){
					counter[nums2[b]]++;
				}
				helper(dp[i][j], cur, counter, dp[i - 1][j], dp[i][j - 1], 0, 0, k);
				for (auto it : dp[i][j]){
					cout << it;
				}
				cout << endl;
			}

		}
	}
	return dp[nums1.size()][nums2.size()];

}