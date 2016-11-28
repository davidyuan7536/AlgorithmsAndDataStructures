#include "leetcode.h"

int Solution::romanNumeralToInt(string num){


	map<char, int> romanMap;
	romanMap.insert(make_pair('M', 1000));
	romanMap.insert(make_pair('D', 500));
	romanMap.insert(make_pair('C', 100));
	romanMap.insert(make_pair('L' , 50));
	romanMap.insert(make_pair('X', 10));
	romanMap.insert(make_pair('V', 5));
	romanMap.insert(make_pair('I', 1));

	int retInt = 0;
	int prev = romanMap.find(num[0])->second; 

	retInt += prev;

	for (int x = 1; x != num.length(); x++){

		int cur = romanMap.find(num[x])->second;
		if (cur > prev){
			retInt += (cur - 2*(prev));
		}
		else{
			retInt += cur; 
		}
		prev = cur; 

	}

	return retInt; 
};