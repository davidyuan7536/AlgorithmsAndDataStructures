#include "leetcode.h"

using namespace std;

int Solution::longestSubstringWithoutRepeatingCharacters(string s){
    
	if (s.empty()){
		return 0;
	}
	unordered_map<char, int> map;
	int length = 1;
	int start = -1;

	for (int x = 0; x != s.length(); x++){

		if (map.find(s[x]) != map.end()){

			if (map.find(s[x])->second > start)
			    start = map.find(s[x])->second;
			if (x - start > length){
				length = x - start;
			}

			map.find(s[x])->second = x;
		}
		else{
			map.insert(make_pair(s[x], x));
			if (x - start > length){
				length = x - start;
			}
		}

	}

	return length;

}

