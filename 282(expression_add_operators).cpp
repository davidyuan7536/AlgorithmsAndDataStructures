#include "leetcode.h"

bool processString(string &current, int target){
    
	string prev = "";
    string cur = "";
	string truePrev = "";
	int total = 0;
	for (int i = 0; i < current.length(); i++){
		if (current[i] == '*'){
			i++;
			cur = "";
			while (i < current.length() && current[i] - '0' >= 0 && current[i] - '0' <= 9){
				cur += current[i];
				i++;
			}
			i--;

			total = (total - stoi(prev)) + (stoi(prev) * stoi(cur));
			prev = to_string(stoi(prev) * stoi(cur));
	
		}
		else if (current[i] == '+'){
			i++;
			cur = ""; 
			while (i < current.length() && current[i] - '0' >= 0 && current[i] - '0' <= 9){
				cur += current[i];
				i++;
			}
			i--;
			prev = cur;
			total += stoi(cur);
		}
		else if (current[i] == '-'){
			i++;
			cur = "";
			while (i < current.length() && current[i] - '0' >= 0 && current[i] - '0' <= 9){
				cur += current[i];
				i++;
			}
			i--;
			prev = cur;
			total -= stoi(cur);
		}
		else{
			prev = "";
			while (i < current.length() && current[i] - '0' >= 0 && current[i] - '0' <= 9){
			    prev += current[i];
				i++;
			}
			i--;
			total = stoi(prev);
		}
	}
	cout << total << endl;
	return total == target ? true : false; 
}

void addOperatorHelper(vector<string> &ret, string &current, string &num, int pos, int &target){

	if (pos == num.size()){
		cout << current << " : ";
		if (processString(current, target)){
			ret.push_back(current);
		}
		return; 
	}

	for (int i = pos; i < num.size(); i++){
		if (num[pos] == '0' && i>pos) break;
		current.push_back(num[i]);
		if (i == num.size() - 1){
			addOperatorHelper(ret, current, num, i + 1, target);
			break;
		}
		current.push_back('*');
		addOperatorHelper(ret, current, num, i+1, target);
		current.pop_back();
		current.push_back('+');
		addOperatorHelper(ret, current, num, i + 1, target);
		current.pop_back();
		current.push_back('-');
		addOperatorHelper(ret, current, num, i + 1, target);
		current.pop_back();
	}
	while (!current.empty() && (current.back() != '*' && current.back() != '+' && current.back() != '-'))
	    current.pop_back();
}

vector<string> Solution::addOperators(string num, int target){

	vector<string> ret;
	string current = "";
	addOperatorHelper(ret, current, num, 0, target);
	return ret; 
}