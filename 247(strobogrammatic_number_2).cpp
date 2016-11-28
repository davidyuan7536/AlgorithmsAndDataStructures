#include "leetcode.h"


void helper(vector<string> &ret, string & current, int n, bool odd, bool first, vector<int> &nums){
	
	if (n == 0){
		ret.push_back(current);
		return;
	}

	for (int i = 0; i < nums.size(); i++){
		if (first && i == 4){
			continue;
		}
		current += to_string(nums[i]);
		helper(ret, current, n-1, odd, false, nums);
		current.pop_back();
		if (odd && n == 1){
			i++;
		}
	}
}

void helper2(vector<string> &ret, int n){
	for (int i = 0; i < ret.size(); i++){
		for (int j = n-1; j >= 0; j--){
			if (ret[i][j] == '6'){
				ret[i] += '9';
			}
			else if (ret[i][j] == '9'){
				ret[i] += '6';
			}
			else {
				ret[i] += ret[i][j];
			}
		}
	}
}

vector<string> Solution::findStrobogrammatic(int n){

	int half = (n+1) / 2;
	bool odd = n & 1; 
	vector<string> ret;
	string current;
	vector<int> nums{ 1, 6, 8, 9, 0 };
	
	if (odd){
		if (n == 1){
			helper(ret, current, half, true, false, nums);
		}
		helper(ret, current, half, true, true, nums);
		helper2(ret, ret[0].length()-1);
	}
	else{
		helper(ret, current, half, false, true, nums);
		helper2(ret, ret[0].length());
	}
	return ret; 
}