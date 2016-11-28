#include "leetcode.h"


struct MyHash
{
	size_t operator()(const unordered_set<char>& set) const
	{
		string ret = "";
		for (auto it : set){
			ret += it;
		}
		sort(ret.begin(), ret.end());
		size_t h = hash<string>{}(ret);
		return h;
	}
};

struct MyEqual{

	bool operator()(const unordered_set<char> &setA, const unordered_set<char> &setB) const{
		return setA == setB; 
	}

};

class isScrambleHelper{

	unordered_set<unordered_set<char>, MyHash, MyEqual> m_set;

public:

	void clear(){
		m_set.clear();
	}

	void insert(unordered_set<char> set){
		m_set.insert(set);
	}

	unordered_set<unordered_set<char>, MyHash, MyEqual> getSet() const{
		return m_set;
	}

	bool operator==(const isScrambleHelper &a) const{
		return a.getSet() == m_set;
	}
};

bool Solution::isScramble(string s1, string s2){
	
	isScrambleHelper helper1;
	isScrambleHelper helper2;

	stack<string> s1_1;
	stack<string> s1_2;
	stack<string> s2_1;
	stack<string> s2_2;

	s1_1.push(s1);
	s2_1.push(s2); 
	
	int counter = 0;
	while ((!s1_1.empty() || !s1_2.empty()) && (!s2_1.empty() || !s2_2.empty())){

		counter++;

		if (counter % 2 != 0){
			while (!s1_1.empty()){
				string top = s1_1.top();
				s1_1.pop();
				if (top.length() > 1){
					int mid = top.length() / 2;
					s1_2.push(top.substr(0, mid));
					s1_2.push(top.substr(mid, top.length() - mid));
				}
				unordered_set<char> tempSet;
				for (int i = 0; i < top.length(); i++){
					tempSet.insert(top[i]);
				}
				helper1.insert(tempSet);
			}

			while (!s2_1.empty()){
				string top = s2_1.top();
				s2_1.pop();
				if (top.length() > 1){
					int mid = top.length() / 2;
					s2_2.push(top.substr(0, mid));
					s2_2.push(top.substr(mid, top.length() - mid));
				}
				unordered_set<char> tempSet;
				for (int i = 0; i < top.length(); i++){
					tempSet.insert(top[i]);
				}
				helper2.insert(tempSet);
			}

			if (!(helper1 == helper2)){
				return false;
			}
			helper1.clear();
			helper2.clear();
		}
		
		else{

			while (!s1_2.empty()){
				string top = s1_2.top();
				s1_2.pop();
				if (top.length() > 1){
					int mid = top.length() / 2;
					s1_1.push(top.substr(0, mid));
					s1_1.push(top.substr(mid, top.length() - mid));
				}
				unordered_set<char> tempSet;
				for (int i = 0; i < top.length(); i++){
					tempSet.insert(top[i]);
				}
				helper1.insert(tempSet);
			}

			while (!s2_2.empty()){
				string top = s2_2.top();
				s2_2.pop();
				if (top.length() > 1){
					int mid = top.length() / 2;
					s2_1.push(top.substr(0, mid));
					s2_1.push(top.substr(mid, top.length() - mid));
				}
				unordered_set<char> tempSet;
				for (int i = 0; i < top.length(); i++){
					tempSet.insert(top[i]);
				}
				helper2.insert(tempSet);
			}

			if (!(helper1 == helper2)){
				return false;
			}

			helper1.clear();
			helper2.clear();

		}
	
	}

	if (s1_1.empty() && s1_2.empty() && s2_1.empty() && s2_2.empty()){
		return true;
	}
	return false;
}