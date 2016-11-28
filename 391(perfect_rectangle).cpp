#include "leetcode.h"

struct Hasher{

	size_t operator()(const pair<int, int> &a) const{
		return (hash<int>()(a.first) ^ (hash<int>()(a.second) << 1));
	}

};


bool insertVerticies(unordered_map<pair<int, int>, int, Hasher> &myMap, vector<int> rec, int &minX, int &minY, int &maxX, int &maxY){
	
	minX = min(minX, rec[0]);
	maxX = max(maxX, rec[2]);
	minY = min(minY, rec[1]);
	maxY = max(maxY, rec[3]);

	pair<int, int> temp = make_pair(rec[0], rec[1]);
	if (myMap.find(temp) != myMap.end()){
		if ((myMap[temp] & 7) > 4 || myMap[temp] & 8){
			return false;
		}
		myMap[temp]++;
	}
	else{
		myMap[temp]++;
		myMap[temp] = myMap[temp] | 8;
	}
	
	temp = make_pair(rec[0], rec[3]);
	if (myMap.find(temp) != myMap.end()){
		if ((myMap[temp] & 7)> 4 || myMap[temp] & 16){
			return false;
		}
		myMap[temp]++;
	}
	else{
		myMap[temp]++;
		myMap[temp] = myMap[temp] | 16;
	}

	temp = make_pair(rec[2], rec[1]);
	if (myMap.find(temp) != myMap.end()){
		if ((myMap[temp] & 7) > 4 || myMap[temp] & 32){
			return false;
		}
		myMap[temp]++;
	}
	else{
		myMap[temp]++;
		myMap[temp] = myMap[temp] | 32;
	}

	temp = make_pair(rec[2], rec[3]);
	if (myMap.find(temp) != myMap.end()){
		if ((myMap[temp] & 7) > 4 || myMap[temp] & 64){
			return false;
		}
		myMap[temp]++;
	}
	else{
		myMap[temp]++;
		myMap[temp] = myMap[temp] | 64;
	}
	return true;
}

bool Solution::isRectangleCover(vector<vector<int>>& rectangles){

	unordered_map<pair<int, int>, int, Hasher> myMap;
	int minX = INT_MAX;
	int minY = INT_MAX;
	int maxX = INT_MIN;
	int maxY = INT_MIN;

	for (int i = 0; i < rectangles.size(); i++){
		if (!insertVerticies(myMap, rectangles[i], minX, minY, maxX, maxY)){
			return false;
		}
	}

	int edgeCounter = 0;
	for (auto it : myMap){
	
		if ((it.second & 7) == 1){
		
			if ((it.first.first == minX || it.first.first == maxX) && (it.first.second == minY || it.first.second == maxY)){
				edgeCounter++;
				if (edgeCounter > 4){
					return false;
				}
			}
			else
				return false;
		}
		else if ((it.second & 7) != 2 && (it.second & 7) != 4){
			return false;
		}
	}
	if (edgeCounter == 4){
		return true;
	}
	else
		return false;
}