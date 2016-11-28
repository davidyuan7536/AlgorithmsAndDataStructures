#include "leetcode.h"

string Solution::removeKdigits(string num, int k){

	if (k == num.length()){
		return "0";
	}

	deque<int> digits;
	string ret = "";

	bool breakOut = false;
	int i = 0;
	for (; i < num.length(); i++){

		if (breakOut){
			break;
		}

		if (digits.empty() || digits.back() < num[i]){
			digits.push_back(num[i]);
			continue;
		}
		while (!digits.empty() && digits.back() > num[i]){
			digits.pop_back();
			k--;
			if (k == 0){
				breakOut = true;
				break;
			}
		}
		digits.push_back(num[i]);

	}
	while (!digits.empty() && k > 0){
		digits.pop_back();
		k--;
	}

	bool notLeadingZero = false;
	while (!digits.empty()){
		if (digits.front() != '0'){
			notLeadingZero = true;
		}
		if (notLeadingZero)
			ret += digits.front();
		digits.pop_front();
	}

	if (i < num.length()){
		ret.append(num.substr(i));
	}

	return ret.empty() ? "0" : ret;
}