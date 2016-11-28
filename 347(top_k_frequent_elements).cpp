#include "leetcode.h"

class MapHeap{

private:
	vector<pair<int, int>> m_heap;
	unordered_map<int, int> m_map;

	void swap(int a, int b){

		m_map[m_heap[a].first] = b;
		m_map[m_heap[b].first] = a;

		pair<int, int> temp = m_heap[a];
		m_heap[a] = m_heap[b];
		m_heap[b] = temp;
	}

	void rotateUp(int pos){
		while (pos > 0){
			int parent = (pos - 1) / 2;
			if (m_heap[parent].second < m_heap[pos].second){
				swap(parent, pos);
			}
			pos = parent; 
		}
	}

	void rotateDown(int pos){

		while (2 * pos + 1 < m_heap.size()){

			int left = 2 * pos + 1;
			int right = 2 * pos + 2;

			if (right < m_heap.size()){
				left = m_heap[left].second > m_heap[right].second ? left : right;
			}

			if (m_heap[pos].second < m_heap[left].second){
				swap(pos, left);
			}
			pos = left; 
		}

	}

	void insert(int num){

		if (m_map.find(num) == m_map.end()){
			int size = m_heap.size();
			m_map[num] = size;
			m_heap.push_back(make_pair(num, 1));
			rotateUp(size);
		}
		else{
			int pos = m_map[num];
			m_heap[pos].second++;
			rotateUp(pos);
		}

	}

public:
	
	MapHeap(vector<int> &nums){

		for (int i = 0; i < nums.size(); i++){
			insert(nums[i]);
		}
	}

	int pop(){
		int ret = m_heap[0].first;
		m_heap[0] = m_heap.back();
		m_heap.pop_back();
		rotateDown(0);
		return ret;
	}

};

vector<int> Solution::topKFrequent(vector<int>& nums, int k){

	MapHeap mh(nums);
	vector<int> ret;
	for (int i = 0; i < k; i++){
		ret.push_back(mh.pop());
	}
	return ret; 
}