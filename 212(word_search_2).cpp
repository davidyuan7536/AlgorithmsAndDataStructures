#include "leetcode.h"

struct TrieNode{
	unordered_map<char, TrieNode*> m_map;
	bool end;
	TrieNode(){
		end = false;
	}
};

class FindWordsTrie{

	TrieNode* m_head;

public:

	FindWordsTrie(){
		m_head = new TrieNode();
	}

	void insert(string word){
		TrieNode * cur = m_head;
		for (int i = 0; i < word.length(); i++){
			if (cur->m_map.count(word[i])){
				cur = cur->m_map[word[i]];
			}
			else{
				TrieNode * temp = new TrieNode();
				cur->m_map[word[i]] = temp;
				cur = temp;
			}
		}
		cur->end = true;
	}

	TrieNode * query(char a, TrieNode * current){
		if (current->m_map.count(a)){
		
			return current->m_map[a];
		}
		else{
			return nullptr;
		}
	}

	TrieNode * head(){
		return m_head;
	}

};

void findWordsHelper(vector<string> &ret, string current, vector<int> &directions, vector<vector<char>>& board, TrieNode * curNode, int x, int y){

	if (curNode->end){
		ret.push_back(current);
		return; 
	}
	
	char temp = board[x][y];
	board[x][y] = '#';
	for (int i = 0; i < 4; i++){
		int newX = x + directions[i];
		int newY = y + directions[i + 1];
		if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && curNode->m_map.count(board[newX][newY]) && board[newX][newY] != '#'){
			findWordsHelper(ret, current + board[newX][newY], directions, board, curNode->m_map[board[newX][newY]], newX, newY);
		}
	}
	board[x][y] = temp; 
	
}

vector<string> Solution::findWords(vector<vector<char>>& board, vector<string>& words){

	FindWordsTrie ft;
	for (int i = 0; i < words.size(); i++){
		ft.insert(words[i]);
	}

	vector<string> ret;
	string current = "";
	vector<int> directions{ 0, -1, 0, 1, 0 };
	for (int i = 0; i < board.size(); i++){
		for (int j = 0; j < board[0].size(); j++){
			if (ft.head()->m_map.count(board[i][j])){
				findWordsHelper(ret, current + board[i][j], directions, board, ft.head()->m_map[board[i][j]], i, j);
			}
			

		}
	}
	return ret;

}