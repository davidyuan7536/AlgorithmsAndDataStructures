#include "leetcode.h"


void helper(int num, string &ret, string s){
	
	for (int i = 0; i < num; i++){
		
		string digit = "";
		for (int j = 0; j < s.length(); j++){
			if (s[j] - '0' >= 0 && s[j] - '0' <= 9){
				digit += s[j];
			}
			else if (s[j] == '['){
				int bracket = 1;
				int counter = 1;
				while (bracket > 0){
					if (s[j + counter] == '['){
						bracket++;
					}
					else if (s[j + counter] == ']'){
						bracket--;
					}
					counter++;
				}
				helper(stoi(digit), ret, s.substr(j+1, counter-2));
				digit = "";
				j += counter-1;
			}
			else{
				ret += s[j];
			}
		}
	}
}


string Solution::decodeString(string s){

	string ret = "";
	helper(1, ret, s);
	return ret; 
}