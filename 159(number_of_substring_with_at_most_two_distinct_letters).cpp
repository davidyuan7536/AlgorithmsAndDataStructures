#include "leetcode.h"

int Solution::lengthOfLongestSubstringTwoDistinct(string s){
	
	if (s.length() <= 2){
		return s.length();
	}
	unordered_map<char, int> m_map;
	m_map[s[0]]++;
	int back = 0;
	int front = 1;
	int len = INT_MIN;
	while (front < s.length()){
		if (m_map.size() < 2 || m_map.find(s[front]) != m_map.end()){
			m_map[s[front++]]++;
		}
		else{
			while (m_map.size() >= 2){
				if (m_map[s[back]] == 1){
					m_map.erase(s[back++]);
				}
				else{
					m_map[s[back++]]--;
				}
			}
			m_map[s[front++]]++;
		}
		len = max(len, front - back);
	}
	return len;
}