#include "leetcode.h"

int Solution::lengthLongestPath(string input){

	int ret = INT_MIN;
	int counter = 0;
	int level = 0;
	bool file = false;
	map<int, int> myMap;
	for (int i = 0; i < input.length(); i++){

		if (input[i] == '\t'){
			level++;
			continue;
		}
		
		if (input[i] == '\n' || i == input.length()-1){
			if (file){
				file = false;
				if (i == input.length() - 1)
					counter++;
				int totalCount = counter;
				for (int i = level - 1; i >= 0; i--){
					totalCount = totalCount + myMap[i] + 1;
				}
				ret = max(ret, totalCount);
			}
			myMap[level] = counter;
			level = 0;
			counter = 0;
			continue;
		}

		else if (input[i] == '.'){
			file = true; 
		}

		counter++; 

	}

	return ret == INT_MIN ? 0 : ret;
}