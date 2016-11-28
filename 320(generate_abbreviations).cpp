#include "leetcode.h"


void helper(vector<string>& ret, string current, string & word, int pos, int cur){
	
	if (pos == word.length()){
		if (cur != 0){
			ret.push_back(current += to_string(cur));
		}
		else{
			ret.push_back(current);
		}
		return;
	}

	helper(ret, current, word, pos + 1, cur + 1);
	string curString = to_string(cur);
	if (cur != 0){
		current += curString;
	}
	helper(ret, current += word[pos], word, pos + 1, 0);
}
vector<string> Solution::generateAbbreviations(string word){
	
	vector<string> ret;
	if (word.empty()){
		return ret;
	}
	string current = "";
	helper(ret, current, word, 0, 0);
	return ret;
}