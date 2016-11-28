#include"leetcode.h"

string Solution::removeDuplicateLetters(string s){

	unordered_map<char, int> count;
	for (int i = 0; i < s.length(); i++){
		count[s[i]]++;
	}

	vector<int> visited(26, 0);
	stack<char> stk;
	string ret = "";
	for (int i = 0; i < s.length(); i++){

		if (visited[s[i] - 'a']){
			count[s[i]]--;
			continue;
		}
		while (!stk.empty() && s[i] < stk.top() && count[stk.top()] > 0){
			visited[stk.top() - 'a']--;
			stk.pop();
		}
		stk.push(s[i]);
		count[s[i]]--;
		visited[s[i] - 'a']++;
	}

	while (!stk.empty()){
		ret += stk.top();
		stk.pop();
	}
	reverse(ret.begin(), ret.end());
	return ret; 
}