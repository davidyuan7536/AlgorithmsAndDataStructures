#include "leetcode.h"

string Solution::addStrings(string num1, string num2){

	int carry = 0;
	int s1 = num1.length()-1;
	int s2 = num2.length()-1;
	string ret;

	while (s1 >= 0 && s2 >= 0){

		int n1 = num1[s1] - '0';
		int n2 = num2[s2] - '0';
		int s = (n1 + n2 + carry) % 10;
		carry = n1 + n2 + carry> 9 ? 1 : 0;
		s1--;
		s2--;
		char sChar = '0' + s;
		ret.insert(0, 1, sChar);
	}

	while (s1 >= 0){
		int n1 = num1[s1] - '0';
		int s = (n1 + carry) % 10;
		carry = n1 + carry> 9 ? 1 : 0;
		s1--;
		char sChar = '0' + s;
		ret.insert(0, 1, sChar);
	}
	while (s2 >= 0){
		int n2 = num2[s2] - '0';
		int s = (n2 + carry) % 10;
		carry = n2 + carry> 9 ? 1 : 0;
		s2--;
		char sChar = '0' + s;
		ret.insert(0, 1, sChar);
	}
	if (carry = 1){
		ret.insert(0, 1, '1');
	}

	return ret;
}