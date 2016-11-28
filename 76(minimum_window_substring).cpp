#include "leetcode.h"

class minWindowHelper{
	
	int m_charsLeft;
	unordered_multimap<char, list<list<pair<char, int>>::iterator>> myMap;
	unordered_map<char, int> occurances; 
	list<pair<char, int>> myList;
	int m_begin;
	int m_length;

public:
	minWindowHelper(string t){
		m_begin = 0;
		m_length = INT_MAX;
		m_charsLeft = t.length(); 

		for (int i = 0; i < t.length(); i++){
			if (occurances.find(t[i]) == occurances.end()){
				occurances.insert(make_pair(t[i], 1));
			}
			else{
				occurances[t[i]]++;
			}
		}
	}

	void process(char t, int pos){
		
		if (occurances.find(t) == occurances.end()){
			return;
		}


		if (myMap.find(t) == myMap.end()){
			myList.push_back(make_pair(t, pos));
			list<list<pair<char, int>>::iterator> temp;
			temp.push_back(--myList.end());
			myMap.insert(make_pair(t, temp));
			m_charsLeft--;
			occurances[t]--;

			if (m_charsLeft == 0 && myList.back().second - myList.front().second < m_length){
				m_length = myList.back().second - myList.front().second;
				m_begin = myList.front().second;
			}
		}
		else{
			if (m_charsLeft == 0){
				myList.erase(myMap.find(t)->second.front());
				myList.push_back(make_pair(t, pos));
				myMap.find(t)->second.pop_front();
				myMap.find(t)->second.push_back(--myList.end());

				if (myList.back().second - myList.front().second < m_length){
					m_length = myList.back().second - myList.front().second; 
					m_begin = myList.front().second;
				}
			}
			else{
				if (occurances.find(t)->second == 0){

					myList.erase(myMap.find(t)->second.front());
					myList.push_back(make_pair(t, pos));
					myMap.find(t)->second.pop_front();
					myMap.find(t)->second.push_back(--myList.end());

				}
				else{
					myList.push_back(make_pair(t, pos));
					myMap.find(t)->second.push_back(--myList.end());
					m_charsLeft--;
					occurances[t]--;
					if (m_charsLeft == 0 && myList.back().second - myList.front().second < m_length){
						m_length = myList.back().second - myList.front().second;
						m_begin = myList.front().second;
					}
				}
			}
		}
			
	}

	int length(){
		return m_length;
	}
	int begin(){
		return m_begin;
	}

};

string Solution::minWindow(string s, string t){

	minWindowHelper helper(t);
	unordered_set<char> characters;
	for (int i = 0; i < t.length(); i++){
		characters.insert(t[i]);
	}

	for (int i = 0; i < s.length(); i++){
		if (characters.find(s[i]) != characters.end()){
			helper.process(s[i], i);
		}
	}

	if (helper.length() == INT_MAX){
		return "";
	}
	return s.substr(helper.begin(), helper.length()+1);

}
