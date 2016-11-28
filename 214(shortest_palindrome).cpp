#include "leetcode.h"


string Solution::shortestPalindrome(string s){
    
	if (s.size() <= 1) return s;
	string srv = s;
	reverse(srv.begin(), srv.end());
	if (srv == s) return s;
	vector<int> next(srv.size(), 0);
	int i = 1, j = 0;
	while (i<srv.size()){
		if (srv[i] == s[j]){
			next[i] = j + 1;
			i++; j++;
		}
		else if (j>0){
			j = next[j - 1];
		}
		else{
			next[i] = 0; i++;
		}
	}
	int k = next.back();
	string res = "";
	for (int i = s.size() - 1; i >= k; i--){
		res += s[i];
	}
	for (auto it : next){
		cout << it << " ";
	}
	cout << endl;
	res += s;
	return res;

}