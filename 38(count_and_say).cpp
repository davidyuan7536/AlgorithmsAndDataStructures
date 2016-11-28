#include "leetcode.h"


string countAndSayHelper(string n){

	char current = n[0];
	int counter = 1;
	string retString;

	if (n.length() == 1){
		return n;
	}

	for (int x = 1; x != n.length(); x++){
		if (n[x] == current){
			counter++;
			continue;
		}
		else{
			retString += to_string(counter);
			retString += current;
			current = n[x];
			counter = 1; 
		}
	}

	retString += to_string(counter);
	retString += current;
	return retString;

}

string Solution::countAndSay(int n){

	string temp = countAndSayHelper(to_string(n));
	for (int x = 1; x != n; x++){
		temp = countAndSayHelper(temp);
	}

	return temp;

}