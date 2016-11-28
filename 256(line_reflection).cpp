#include "leetcode.h"

bool isReflected(vector<pair<int, int>>& points){

	int minx = INT_MAX, maxx = INT_MIN;
	unordered_map<int, int> point_map;
	for (auto point : points){
		minx = min(minx, point.first);
		maxx = max(maxx, point.first);
		point_map[point.first] = point.second;
	}
	for (auto iter = point_map.begin(); iter != point_map.end(); iter++){
		int to_find = minx + maxx - iter->first;
		if (point_map.find(to_find) == point_map.end() || point_map[to_find] != iter->second){
			return false;
		}
	}
	return true;
}