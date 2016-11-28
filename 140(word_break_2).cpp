#include "leetcode.h"

bool isInDict(string s, unordered_set<string> & wordDict){
	return wordDict.find(s) == wordDict.end() ? false : true;
}

void getAllStringCombination(vector<string> &ret, string current, string &s, int left, vector<vector<int>> &dp, bool push){

	if (push){
		current.pop_back();
		ret.push_back(current);
		return;
	}

	for (int i = left; i < s.length(); i++){
		if (dp[left][i] == 1){
			string temp = s.substr(left, i-left+1);
			temp += " ";
			getAllStringCombination(ret, current + temp, s, i + 1, dp, i == s.length() - 1 ? true : false);
		}
	}

}

void pp(vector<vector<int>>& posToVStr, string& s, int pos, string thisLine, vector<string>& vRes){
	if (pos == 0){
		vRes.push_back(thisLine);
		return;
	}


	for (int i = 0; i<posToVStr[pos].size(); i++){
		string tmp;
		if (thisLine == ""){
			tmp = s.substr(posToVStr[pos][i], pos - posToVStr[pos][i]);
		}
		else{
			tmp = s.substr(posToVStr[pos][i], pos - posToVStr[pos][i]) + " " + thisLine;
		}
		pp(posToVStr, s, posToVStr[pos][i], tmp, vRes);
	}
}


void getAllStringCombination2(vector<string> &ret, string current, string &s, int left, unordered_map<int, int> jumpMap, int maxLen, unordered_set<string>& wordDict){

	if (left == s.length()){
		current.pop_back();
		ret.push_back(current);
		return;
	}

	if (jumpMap.find(left) != jumpMap.end()){
		string temp = s.substr(left, jumpMap[left]);
		temp += " ";
		getAllStringCombination2(ret, current + temp, s, jumpMap[left] + left,jumpMap, maxLen, wordDict);
		return;
	}


	for (int i = left; i < s.length() && i <= left + maxLen; i++){
		if (isInDict(s.substr(left, i - left + 1), wordDict)){
			jumpMap.insert(make_pair(left, i - left + 1));
			string temp = s.substr(left, i - left + 1);
			temp += " ";
			getAllStringCombination2(ret, current + temp, s, i + 1, jumpMap, maxLen, wordDict);
		}
	}
}

vector<string> Solution::wordBreak(string s, unordered_set<string>& wordDict){

	vector<string> vRes;
	int len = s.size();
	if (len <= 0){
		return vector<string>();
	}


	///< find the longest wordLength in dict: this will save lots of time unless longestWord is very long
	int longestWord = 0;
	for (string word : wordDict){
		longestWord = max(longestWord, int(word.size()));
	}


	///< DP
	///< for each pos in s, we record all of its possible preNode
	///< (the last character of the word before it) 
	vector<vector<int>> posToVStr(s.size() + 1, vector<int>());
	posToVStr[0].push_back(0);
	for (int i = 1; i <= len; i++){
		///< 
		for (int j = i - 1; i - j <= longestWord && j >= 0; j--){
			if (posToVStr[j].size() >0 && wordDict.find(s.substr(j, i - j)) != wordDict.end()){
				posToVStr[i].push_back(j);
			}
		}
	}
	int counter = 0;
	for (auto it : posToVStr){
		cout << counter << " : ";
		for (auto it2 : it){
			cout << it2 << " ";
		}
		cout << endl;
		counter++;
	}

	cout << endl;
	pp(posToVStr, s, len, "", vRes);
	return vRes;

}