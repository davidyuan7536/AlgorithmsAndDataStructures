#include "leetcode.h"

bool Solution::isValidSerialization(string preorder){

	if (preorder.size() == 1 && preorder[0] == '#')
		return true;

	stack<pair<string, int>> m_stack;
	string cur = "";
	for (int i = 0; i < preorder.length(); i++){
		if (preorder[i] == ','){
			if (cur == ""){
				continue;
			}
			m_stack.push(make_pair(cur, 2));
			cur = "";
			continue;
		}
		if (preorder[i] != '#'){
			cur += preorder[i];
		}
		else{
			if (m_stack.empty())
				return false;
			m_stack.top().second--;
		}
		while (!m_stack.empty() && m_stack.top().second == 0){
			m_stack.pop();
			if (!m_stack.empty())
				m_stack.top().second--;
			else{
				if (i != preorder.length() - 1){
					return false;
				}
			}
		}
	}
	return m_stack.empty() && cur == "" ? true : false;

}