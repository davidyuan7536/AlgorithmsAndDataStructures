#include "leetcode.h"


bool matchHelper(string s, string p, unordered_map<string, bool> &m_map){

	if (s.length() == 0 && p.length() == 0 || (s.length() == 0)){
		if (s.length() == 0 && p.length() != 0){
			if (p.length() & 1){
				return false;
			}
			for (int i = 1; i < p.length(); i += 2){
				if (p[i] != '*'){
					return false;
				}
			}
			return true;
		}
		return true;
	}
	if (p.length() == 0){
		return false;
	}

	if (m_map.find(s) != m_map.end()){
		return m_map[s+p];
	}

	if (s[0] == p[0] || p[0] == '.'){
		if (p.length() > 1 && p[1] == '*'){
			if (matchHelper(s.substr(1), p, m_map)){
				return true;
			}
			else{
				string temp = s.substr(1) + p;
				m_map[temp] = false;
				if (matchHelper(s, p.substr(2), m_map)){
					return true;
				}
				else{
					string temp = s + p.substr(2);
					m_map[temp] = false;
				}
			}
			return false;
		}
		else{
			return matchHelper(s.substr(1), p.substr(1), m_map);
		}
	}
	else{
		if (p.length() > 1 && p[1] == '*'){
			return matchHelper(s, p.substr(2), m_map);
		}
		else{
			return false;
		}
	}

}

bool Solution::isMatch(string s, string p){
	unordered_map<string, bool> m_map;
	return matchHelper(s, p, m_map);
}