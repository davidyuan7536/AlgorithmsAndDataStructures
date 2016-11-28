#include "leetcode.h"


class BinaryTrie{

	struct BinaryTrieNode{
		vector<BinaryTrieNode*> m_map;
		BinaryTrieNode(){
			m_map.push_back(nullptr);
			m_map.push_back(nullptr);
		}
	};

	BinaryTrieNode * m_head = nullptr;

public:

	void addNumer(int num){
		vector<int> bits;
		for (int i = 31; i >= 0; i--){
			bits.push_back((num & (1 << i)) == 0 ? 0 : 1);
		}
		insertBit(m_head, bits);
	}

	void insertBit(BinaryTrieNode *& head, vector<int> bits){

		if (head == nullptr){
			head = new BinaryTrieNode;
		}
		
		BinaryTrieNode * cur = head;

		for (int i = 0; i < bits.size(); i++){
			if (bits[i]){
				if (!cur->m_map[1])
					cur->m_map[1] = new BinaryTrieNode;
				cur = cur->m_map[1];
			}
			else{
				if (!cur->m_map[0])
					cur->m_map[0] = new BinaryTrieNode;
				cur = cur->m_map[0];
			}
		}
	}

	void getMax(vector<int> &a, vector<int> &b, BinaryTrieNode * head1, BinaryTrieNode * head2, int &max, int &first, int &second){
		if (head1->m_map[0] == nullptr && head1->m_map[1] == nullptr){
			
			int aVal = 0;
			int bVal = 0;
			for (int i = 0; i < a.size(); i++){
				if (a[i]){
					aVal |= 1 << (31-i);
				}
				if (b[i]){
					bVal |= 1 << (31 - i);
				}
			}
			if ((aVal ^ bVal) > max){
				max = aVal ^ bVal;
				first = aVal;
				second = bVal;
			}
			return;
		}


		if (head1 == head2 && head1->m_map[0] && head1->m_map[1]){
			a.push_back(0);
			b.push_back(1);
			getMax(a, b, head1->m_map[0], head2->m_map[1], max, first, second);
			a.pop_back();
			b.pop_back();
			return;
		}
		if (head1 == head2){
			if (head1->m_map[0]){
				a.push_back(0);
				b.push_back(0);
				getMax(a, b, head1->m_map[0], head2->m_map[0], max, first, second);
			}
			else{
				a.push_back(1);
				b.push_back(1);
				getMax(a, b, head1->m_map[1], head2->m_map[1], max, first, second);
			}
			a.pop_back();
			b.pop_back();
			return;
		}

		if ((head1->m_map[0] && head2->m_map[1]) || (head1->m_map[1] && head2->m_map[0])){
			if (head1->m_map[0] && head2->m_map[1]){
				a.push_back(0);
				b.push_back(1);
				getMax(a, b, head1->m_map[0], head2->m_map[1], max, first, second);
				a.pop_back();
				b.pop_back();
			}
			if (head1->m_map[1] && head2->m_map[0]){
				a.push_back(1);
				b.push_back(0);
				getMax(a, b, head1->m_map[1], head2->m_map[0], max, first, second);
				a.pop_back();
				b.pop_back();
			}
			return;
		}
		else{
			if (head1->m_map[0]){
				a.push_back(0);
				b.push_back(0);
				getMax(a, b, head1->m_map[0], head2->m_map[0], max, first, second);
			}
			else{
				a.push_back(1);
				b.push_back(1);
				getMax(a, b, head1->m_map[1], head2->m_map[1], max, first, second);
			}
			a.pop_back();
			b.pop_back();
			return;
		}

	}

	BinaryTrieNode * headNode(){
		return m_head;
	}
};


int Solution::findMaximumXOR(vector<int>& nums){

	BinaryTrie bt;
	for (auto it : nums){
		bt.addNumer(it);
	}
	int max = INT_MIN;
	int first = 0;
	int second = 0;
	vector<int> a;
	vector<int> b;
	bt.getMax(a, b, bt.headNode(), bt.headNode(), max, first, second);
	cout << first << endl << second << endl;
	return max;
}