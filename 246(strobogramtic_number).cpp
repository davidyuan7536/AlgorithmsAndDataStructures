#include "leetcode.h"

bool Solution::isStrobogrammatic(string num){
	

	for (int i = 0; i < num.length() / 2; i++){
		if (num[i] != '0' && num[i] != '8' && num[i] != '6' && num[i] != '9' && num[i] != '1'){
			return false;
		}
		if (num[i] == '0' && num[num.length() - i - 1] != '0'){
			return false;
		}
		if (num[i] == '1' && num[num.length() - i - 1] != '1'){
			return false;
		}
		if (num[i] == '6' && num[num.length() - i - 1] != '9'){
			return false;
		}
		if (num[i] == '9' && num[num.length() - i - 1] != '6'){
			return false;
		}
	}
	if (num.length() % 2 == 0){
		return true;
	}
	return num[num.length() / 2] == '1' || num[num.length() / 2] == '0' || num[num.length() / 2] == '8' ? true : false;
}