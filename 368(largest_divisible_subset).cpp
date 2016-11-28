#include "leetcode.h"

using namespace std;

vector<int> Solution::largestDivisibleSubset(vector<int>& nums)
{

	if (nums.size() == 0){
		return nums;
	}

	sort(nums.begin(), nums.end());

	vector<pair<int, int>> dp(nums.size());
	for (int x = 0; x != nums.size(); x++){
		dp[x] = make_pair(1, x);
	}


	int largest = 1;
	int largestIndex = 0;

	for (int x = nums.size() - 2; x >= 0; x--){
		for (int y = x + 1; y<nums.size(); y++){
			if (nums[y] % nums[x] == 0){
				if (dp[x].first < dp[y].first + 1){
					dp[x].first = dp[y].first + 1;
					dp[x].second = y;
					if (dp[x].first > largest){
						largest = dp[x].first;

						largestIndex = x;
					}
				}
			}
			else{
				continue;
			}
		}
	}

	vector<int> retArray;
	for (int x = 0; x != largest; x++){
		retArray.push_back(nums[largestIndex]);
		largestIndex = dp[largestIndex].second;
	}


	return retArray;
}