#include "leetcode.h"

struct sorter{
	bool operator()(const pair<int, int> &a, const pair<int, int> &b) const{
		if (a.first == b.first){
			return a.second < b.second;
		}
		else
			return a.first > b.first;
	}
};

void insertAtPos(list<pair<int, int>> &list, int pos, pair<int, int> val){
	auto it = list.begin();
	advance(it, pos);
	list.insert(it, val);
}

vector<pair<int, int>> Solution::reconstructQueue(vector<pair<int, int>>& people){
	
	sort(people.begin(), people.end(), sorter());
	
	list<pair<int, int>> myList;
	for (int i = 0; i < people.size(); i++){
		insertAtPos(myList, people[i].second, people[i]);
	}
	
	return vector<pair<int, int>>(myList.begin(), myList.end());
}