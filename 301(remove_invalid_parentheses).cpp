#include "leetcode.h"


void generateSets(vector<set<string>> &ret, int current, string generated, string s, int num){



	if (num <= 0){
		string temp = generated;
		generated += s;
		ret[current].insert(generated);
		generated = temp;
		return;
	}

	if (s.length() <= 0){
		return;
	}

	for (int i = 0; i < s.length(); i++){
		if (s[i] == ')'){
			generateSets(ret, current, generated, s.substr(i+1, s.length()-i+1), num-1);
			generated += s[i];
		}
		else
			generated += s[i];
	}

}

void multipleSet(set<string> &a, set<string> &b){

	set<string> c;
	for (auto it : a){
		for (auto it2 : b){
			c.insert(it + it2);
		}
	}
	b.clear();
	b = c;

}

void helper(vector<string> &ret, vector<vector<int>> posMap, string s){

	
	vector<set<string>> mySet(posMap.size(), set<string>());
	
	int current = 0;
	int previousEnd = 0;
	for (auto it = posMap.begin(); it != posMap.end(); it++){
		string generated = "";
	
		generateSets(mySet, current, generated, s.substr(it->at(0), it->at(1) - it->at(0)), it->at(2));
		previousEnd = it->at(1);
		current++;
	}

	if (mySet.size() > 1){
		for (int i = 1; i < mySet.size(); i++){
			multipleSet(mySet[i - 1], mySet[i]);
		}
	}

	
	if (previousEnd < s.length()){
		if (mySet.back().empty()){
			string temp = s.substr(previousEnd, s.length() - previousEnd);
			if (temp[0] != '(')
				ret.push_back(s.substr(previousEnd, s.length() - previousEnd));
		}
		else{
			for (auto it = mySet.back().begin(); it != mySet.back().end(); it++){
				string temp = s.substr(previousEnd, s.length() - previousEnd);
				temp = *it + temp;
				ret.push_back(temp);
			}
		}

	}
	else{
		for (auto it = mySet.back().begin(); it != mySet.back().end(); it++){
			ret.push_back(*it);
		}
	}
	
}

void flip(char &a){
	if (a == '(')
		a = ')';
	else if (a == ')')
		a = '(';
}

void reverseStr(string &str)
{
	int n = str.length();

	// Swap character starting from two
	// corners
	for (int i = 0; i < n / 2; i++){
		flip(str[i]);
		flip(str[n - i - 1]);
		swap(str[i], str[n - i - 1]);
	}
	
	if (n % 2 != 0){
		flip(str[n / 2]);
	}

}

void removeClosing(set<string> &ret , string s, int num){
	
	if (num == 0){
		int valid = 0;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == ')'){
				valid--;
			}
			else if (s[i] == '('){
				valid++;
			}
			if (valid < 0){
				return;
			}
		}
		ret.insert(s);
		return;
	}

	for (int i = s.length() - 1; i >= 0; i--){
		if (s[i] == '('){
			string temp = s;
			s.erase(i, 1);
			removeClosing(ret, s, num - 1);
			s = temp;
		}
	}
}

vector<string> Solution::removeInvalidParentheses(string s){

	stack<char> stac;
	vector<char> charStac;
	vector<vector<int>> posMap;
	   
	int reverse = 0;
	bool valid = true;
	for (int i = 0; i < s.length(); i++){
		if (s[i] ==  '('){
			reverse++;
		}
		else if (s[i] == ')'){
			reverse--;
		}
		if (reverse < 0)
			valid = false;
	}

	if (valid && reverse == 0){
		return vector<string>{s};
	}
	else if (reverse > 0){
		reverseStr(s);
	}
	

	bool hasPrevious = false;
	
	int posOfFirstOpen(0);
	int posOfLastProcessed(0);
	for (int i = 0; i < s.length(); i++){
		if (s[i] != ')'){
			if (!hasPrevious){
				posOfFirstOpen = i;
			}

			if (s[i] == '('){
				stac.push('(');
			}
			else{
				charStac.push_back(s[i]);
			}
			hasPrevious = true;
		}
		else if (s[i] == ')'){
			if (stac.empty()){
				if (hasPrevious){
					int counter = 1;
					int bracketCounter = 1;
					while (i + counter < s.length() && s[i + counter] != '('){
						if (s[i + counter] == ')'){
							bracketCounter++;
						}
						counter++;
					}
					vector<int> temp{ posOfFirstOpen, i + counter, bracketCounter };
					posMap.push_back(temp);
					i = i + counter - 1;
					posOfLastProcessed = i + 1;
					charStac.clear();
					
				}
				else{
					int counter = 1;
					while (i + counter < s.length() && s[i + counter] == ')'){
						counter++;
					}
					i = i + counter - 1;
					posOfLastProcessed = i + 1;
					
				}
				hasPrevious = false; 
				continue;
			}
			else{
				stac.pop();
			}
		}
	}


	vector<string> ret;

	if (!posMap.empty())
		helper(ret, posMap, s);

	if (!stac.empty()){
		if (ret.empty()){
			string temp = "";
			
			for (int i = posOfLastProcessed; i < s.length(); i++){
				
				temp += s[i];
			}

			int counter = stac.size();
			/*
			for (int i = temp.length() - 1; i >= 0; i--){
				
				if (temp[i] == '('){
					counter--;
					temp.erase(i, 1);
					if (counter <= 0){
						break;
					}
				}
			}

			ret.push_back(temp);
			*/
			set<string> tempSet;
			removeClosing(tempSet, temp, counter);
			ret.resize(tempSet.size());
			copy(tempSet.begin(), tempSet.end(), ret.begin());
		}
		else{
			for (auto &it : ret){
				int counter = stac.size();
				for (int i = it.length(); i >= 0; i--){
					if (it[i] == '('){
						counter--;
						it.erase(i, 1);
						if (counter <= 0){
							break;
						}
					}
				}
			}
		}
	}
	else if (!charStac.empty()){
	
		if (ret.empty()){
			string temp = "";
			for (int i = posOfLastProcessed; i < s.length(); i++){
				temp += s[i];
			}
			ret.push_back(temp);
		}
	
	}
	else if (posOfFirstOpen >= posOfLastProcessed){
		if (ret.empty()){
			string temp = "";
			for (int i = posOfFirstOpen; i < s.length(); i++){
				temp += s[i];
			}
			ret.push_back(temp);
		}
	
	}

	if (reverse > 0){
		for (auto &it : ret){
			reverseStr(it);
		}
	}

	if (ret.empty())
		ret.push_back("");
	return ret;
}