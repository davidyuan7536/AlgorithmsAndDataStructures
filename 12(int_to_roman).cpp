#include "leetcode.h"

class CompareMap{

public:
	bool operator()(const int & a, const int &b){
		return a > b; 
	}
};

string Solution::intToRomanNumeral(int x){

	list<pair<int, string>> romanMap;
	romanMap.push_back(make_pair(1000, "M"));
	romanMap.push_back(make_pair(900, "CM"));
	romanMap.push_back(make_pair(500, "D"));
	romanMap.push_back(make_pair(400, "CD"));
	romanMap.push_back(make_pair(100, "C"));
	romanMap.push_back(make_pair(90, "XC"));
	romanMap.push_back(make_pair(50, "L"));
	romanMap.push_back(make_pair(40, "XL"));
	romanMap.push_back(make_pair(10, "X"));
	romanMap.push_back(make_pair(9, "IX"));
	romanMap.push_back(make_pair(5, "V"));
	romanMap.push_back(make_pair(4, "IV"));
	romanMap.push_back(make_pair(1, "I"));

	string retString;
	while(!romanMap.empty()){

		while (x - romanMap.front().first >= 0){
			retString += romanMap.front().second; 
			x -= romanMap.front().first;
		}
		romanMap.pop_front();

	}
	
	return retString; 
}