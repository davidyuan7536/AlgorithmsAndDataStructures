#include "leetcode.h"

struct LenSorter{

	bool operator()(const string &a, const string &b)const{
		return a.length() > b.length();
	}

};

bool repeatLetters(string &a, vector<int> &hash){

	for (int i = 0; i < a.length(); i++){
		if (hash[a[i] - 'a'] != 0){
			return true;
		}
	}
	return false;
}

int Solution::maxProduct(vector<string>& words){

	if (words.size() <= 1){
		return 0;
	}

	sort(words.begin(), words.end(), LenSorter());

	int checkUntil = words.size();
	int maxLen = 0;
	for (int i = 0; i < checkUntil; i++){

		string curWord = words[i];
		vector<int> hash(26, 0);
		for (int j = 0; j < curWord.length(); j++){
			hash[curWord[j] - 'a']++;
		}
		for (int k = i + 1; k < checkUntil; k++){
			if (!repeatLetters(words[k], hash) && words[i].length() * words[k].length() > maxLen){
				maxLen = words[i].length() * words[k].length();
				checkUntil = k;
				break;
			}
		}
	}

	return maxLen;
}