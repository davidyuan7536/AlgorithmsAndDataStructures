#include "leetcode.h"


int Solution::lengthOfLongestSubstringKDistinct(string s, int k){
	
	if (k <= 0 || s.empty()){
		return 0;
	}
	if (k >= s.length()){
		return s.length();
	}

	int retMax = INT_MIN;
	unordered_map<char, int> myMap;
	string::iterator first = s.begin();
	string::iterator second = s.begin();

	while (second != s.end()){

		if (myMap.size() > k){
			if (myMap[*first] == 1){
				myMap.erase(*first);
			}
			else{
				myMap[*first]--;
			}
			first++;
			continue;
		}

		
		myMap[*second]++;
	

		if (myMap.size() <= k)
			retMax = max(retMax, second - first + 1);

		second++;
	}

	return retMax;
}