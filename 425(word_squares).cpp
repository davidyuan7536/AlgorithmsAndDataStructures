#include "leetcode.h"

class Trie{

private:
	struct trieNode{
		unordered_map<char, trieNode*> trieMap; 
		bool end;
		set<int> index; 
		trieNode(){
			end = false;
		}
	};

	trieNode* head;

public:

	Trie(){
		head = new trieNode();
	}

	Trie(vector<string> &words){
		head = new trieNode();
		for (int i = 0; i < words.size(); i++){
			insert(words[i], i);
		}
	}

	void insert(string word, int index){
		trieNode * cur = head;
		for (int i = 0; i < word.length(); i++){
			if (cur->trieMap.find(word[i]) == cur->trieMap.end()){
				trieNode *newNode = new trieNode(); 
				cur->trieMap.insert(make_pair(word[i], newNode));
				cur->index.insert(index);
				cur = newNode;
			}
			else{
				cur->index.insert(index);
				cur = cur->trieMap[word[i]];
			}

		}
		cur->end = true;
		cur->index.insert(index);
	}

	bool queryWord(string word, set<int> &index){
		trieNode * cur = head;
		for (int i = 0; i < word.length(); i++){
			if (cur->trieMap.find(word[i]) == cur->trieMap.end()){
				return false;
			}
			else{
				cur = cur->trieMap[word[i]];
			}

		}
		index = cur->index;
		return cur->end == true ? true : false; 
	}

	bool queryPrefix(string prefix, set<int> &index){
		trieNode * cur = head;
		for (int i = 0; i < prefix.length(); i++){
			if (cur->trieMap.find(prefix[i]) == cur->trieMap.end()){
				return false;
			}
			else{
				cur = cur->trieMap[prefix[i]];
			}

		}
		index = cur->index;
		return true;
	}
};


bool checkIfSquare(vector<string> & temp){
	

	int cur = 0;
	for (int i = 0; i < temp.size(); i++){
		for (int j = i; j < temp[i].size(); j++){
			if (temp[i][j] != temp[j][cur])
				return false;
		}
		cur++;  
	}
	return true;
}

void helper(vector<vector<string>>&ret, vector<string> & temp, vector<string>&words, int num){

	if (num == 0){
		if (checkIfSquare(temp)){
			ret.push_back(temp);
			return;
		}
		else{
			return;
		}
	}

	for (int i = 0; i < words.size(); i++){
		temp.push_back(words[i]);
		helper(ret, temp, words, num - 1);
		temp.pop_back();
	}

}

void helper2(vector<vector<string>> &ret, vector<string> &temp, vector<string> &words, int size, set<int> indexes, Trie & myTrie, vector<string> prefix, int pos, int nums){

	if (temp.size() == size){
		ret.push_back(temp);
		return;
	}

	for (auto it : indexes){

		string word = words[it];
		vector<string> prefixMem = prefix;
		for (int j = pos; j < word.size(); j++){
			prefix[j] += word[j];
		}

		set<int> index;
		if (nums != size){
			if (!(myTrie.queryPrefix(prefix[pos], index))){
				prefix = prefixMem;
				continue;
			}
		}

		temp.push_back(word);
		helper2(ret, temp, words, size, index, myTrie, prefix, pos+1, nums+1); 
		temp.pop_back();
		prefix = prefixMem; 
	}

}

vector<vector<string>> Solution::wordSquares(vector<string>& words){

	Trie myTrie(words);

	
	vector<vector<string>> ret; 
	vector<string> temp;
	int size = words[0].length();
	set<int> indexes;
	vector<string> prefix;

	for (int i = 0; i < words.size(); i++){
		indexes.insert(i);
		
	}
	for (int i = 0; i < words[0].size(); i++){
		prefix.push_back("");
	}
	
	helper2(ret, temp, words, size, indexes, myTrie, prefix, 1, 1);
	
	return ret;
}