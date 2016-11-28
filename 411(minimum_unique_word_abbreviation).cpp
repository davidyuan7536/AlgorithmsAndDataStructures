#include "leetcode.h"

class TrieDict{

	struct TrieNode{
		unordered_map<char, TrieNode*> m_map;
		bool m_endOfWord;
		TrieNode(){
			m_endOfWord = false;
		}
	};

	TrieNode* m_head;

public:

	TrieDict(){
		m_head = new TrieNode();
	}

	void insert(string word){
		TrieNode * cur = m_head;
		for (int i = 0; i < word.length(); i++){
			if (cur->m_map.find(word[i]) == cur->m_map.end()){
				TrieNode * temp = new TrieNode();
				cur->m_map[word[i]] = temp;
				cur = temp;
			}
			else
				cur = cur->m_map[word[i]];
		}
		cur->m_endOfWord = true;
	}

	bool queryHelper(string word, TrieNode* current, int num){
		
		if (num != 0){
			if (current->m_endOfWord && current->m_map.empty()){
				return false;
			}
			for (auto it : current->m_map){
				if (queryHelper(word, it.second, num - 1)){
					return true;
				}
			}
			return false;
		}

		string numString = "";
		for (int i = 0; i < word.length(); i++){
			if (word[i] - '0' >= 0 && word[i] - '0' <= 9){
				numString += word[i];
			}
			else{
				if (numString != ""){
					if (queryHelper(word.substr(i), current, stoi(numString))){
						return true;
					}
					else{
						return false;
					}
				}

				if (current->m_map.find(word[i]) == current->m_map.end()){
					return false;
				}
				else{
					current = current->m_map[word[i]];
				}
			}
		}
		if (numString != ""){
			if (queryHelper("", current, stoi(numString))){
				return true;
			}
			else{
				return false;
			}
		}
		if (current->m_endOfWord){
			return true;
		}
		else
			return false;
	}

	bool query(string word){
		TrieNode* current = m_head;
		return queryHelper(word, current, 0);
	}

};


void generateAbrev(vector<string>& ret, string current, string & word, int pos, int cur){

	if (pos == word.length()){
		if (cur != 0){
			ret.push_back(current += to_string(cur));
		}
		else{
			ret.push_back(current);
		}
		return;
	}

	generateAbrev(ret, current, word, pos + 1, cur + 1);
	string curString = to_string(cur);
	if (cur != 0){
		current += curString;
	}
	generateAbrev(ret, current += word[pos], word, pos + 1, 0);
}

struct LenSort{
	bool operator()(const string &a, const string &b)const{
		int counter1 = 0, counter2 = 0;
		bool count = true;
		for (int i = 0; i < a.length(); i++){
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9){
				if (count)
					counter1++;
				count = false;
			}
			else{
				counter1++;
				count = true;
			}
		}
		count = true;
		for (int i = 0; i < b.length(); i++){
			if (b[i] - '0' >= 0 && b[i] - '0' <= 9){
				if (count)
					counter2++;
				count = false;
			}
			else{
				counter2++;
				count = true;
			}
		}
		return counter1 < counter2;
	}
};

string Solution::minAbbreviation(string target, vector<string>& dictionary){

	if (dictionary.empty()){
		return to_string(target.length());
	}

	TrieDict myTrie; 
	for (int i = 0; i < dictionary.size(); i++){
		myTrie.insert(dictionary[i]);
	}

	vector<string> abrev;
	string current = "";
	generateAbrev(abrev, current, target, 0, 0);
	sort(abrev.begin(), abrev.end(), LenSort());

	for (auto it : abrev){
		if (!myTrie.query(it)){
			return it;
		}
	}

	return "";
}