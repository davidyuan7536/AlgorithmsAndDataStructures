#include "leetcode.h"

void helper(vector<vector<int>>& com, vector<int>& candidates, vector<int>& temp, int target, int index)
{
	if (target == 0)
	{
		com.push_back(temp);
		return;
	}
	for (int i = index; i < candidates.size() && target >= candidates[i]; i++)
	{
		if (i != index && candidates[i] == candidates[i - 1])
			continue;
		temp.push_back(candidates[i]);
		helper(com, candidates, temp, target - candidates[i], i + 1);
		temp.pop_back();
	}

}

vector<vector<int>> Solution::combinationSum2(vector<int> &candidates, int target){
	
	vector<vector<int>> com;
	vector<int> temp;
	sort(candidates.begin(), candidates.end());
	helper(com, candidates, temp, target, 0);
	return com;
}



