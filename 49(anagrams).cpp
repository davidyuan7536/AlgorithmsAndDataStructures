#include "leetcode.h"


void sortString(string &s){

	vector<int> cs(26, 0);

	for (int x = 0; x != s.length(); x++){
		cs[s[x] - 'a'] += 1; 
	}


	for (int x = 1; x != 26; x++){
		cs[x] += cs[x - 1];
	}

	string retString(s.length(), 'a');
	for (int x = 0; x != s.length(); x++){
		
		retString[cs[s[x] - 'a']-1] = s[x];
		cs[s[x] - 'a']--;
	}
	s = retString;
	
}

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs){

	vector<vector<string>> retString;
	unordered_map<string, unordered_multiset<string>> myMap;

	for (auto it = strs.begin(); it != strs.end(); it++){
		string temp = *it;
		sortString(temp);

		if (myMap.find(temp) != myMap.end()){
			myMap.find(temp)->second.insert(*it);
		}
		else{
			unordered_multiset<string> tempSet{ *it };
			myMap.insert(make_pair(temp, tempSet));
		}
	}

	for (auto it = myMap.begin(); it != myMap.end(); it++){
		vector<string> temp(it->second.begin(), it->second.end());
		retString.push_back(temp);
	}

	return retString;

}