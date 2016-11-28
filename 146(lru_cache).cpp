#include "leetcode.h"

class LRUCache{
private:
	int m_capacity;
	list<pair<int, int>> myList;
	unordered_map<int, list<pair<int, int>>::iterator> cache;
public:
	LRUCache(int capacity) {
		m_capacity = capacity;
	}

	int get(int key) {

		if (cache.find(key) == cache.end()){
			return -1;
		}
		else{
			int retVal = cache.find(key)->second->second;
			set(key, cache.find(key)->second->second);
			return retVal;
		}

	}


	void set(int key, int value) {

		if (cache.find(key) != cache.end()){
			myList.erase(cache.find(key)->second);
			myList.push_front(make_pair(key, value));
			cache.find(key)->second = myList.begin();
			return;
		}

		if (cache.size() == m_capacity){
			cache.erase(myList.back().first);
			myList.pop_back();
		}
		myList.push_front(make_pair(key, value));
		cache.insert(make_pair(key, myList.begin()));

	}


};