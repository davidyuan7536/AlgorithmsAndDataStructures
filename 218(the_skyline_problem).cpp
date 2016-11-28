#include "leetcode.h"

struct BuildingsSort{

	bool operator()(const vector<int> &a, const vector<int> &b)const{
		if (a[2] == b[2]){
			return a[0] < b[0];
		}
		else{
			return a[2] > b[2];
		}
	}

};

struct RetSort{

	bool operator()(const pair<int, int> &a, const pair<int, int> &b)const{
		return a.first < b.first;
	}
};

void fillGap(vector<pair<int, int>> &ret, vector<pair<int, int>> &gap, int l, int r, int height){

	auto it = gap.begin();
	while (it != gap.end()){

		if (l <= it->first && r >= it->second){
			ret.push_back(make_pair(it->first, height));
			gap.erase(it);
		}
		else if (l < it->first && r > it->first && r < it->second){
			ret.push_back(make_pair(it->first, height));
			it->first = r;
			it++;
		}
		else if (l > it->first && l < it->second && r > it->second){
			ret.push_back(make_pair(l, height));
			it->second = l;
			it++;
		}
		else if (l >= it->first && r <= it->second){
			ret.push_back(make_pair(l, height));
			if (it->first != l)
				gap.push_back(make_pair(it->first, l));
			if (it->second != r)
				gap.push_back(make_pair(r, it->second));
			gap.erase(it);
			break;
		}
		else
			it++;
	}

}


vector<pair<int, int>> Solution::getSkyline(vector<vector<int>>& buildings){

	vector<pair<int, int>> ret;
	if (buildings.empty()){
		return ret;
	}

	auto heightMap = buildings;
	sort(heightMap.begin(), heightMap.end(), BuildingsSort());

	vector<pair<int, int>> gap;
	int left = 0;
	int right = 0;

	for (int i = 0; i < heightMap.size(); i++){

		if (left == 0 && right == 0){
			ret.push_back(make_pair(heightMap[i][0], heightMap[i][2]));
			left = heightMap[i][0];
			right = heightMap[i][1];
			continue;
		}

		if (heightMap[i][0] >= left && heightMap[i][1] <= right){
			fillGap(ret, gap, heightMap[i][0], heightMap[i][1], heightMap[i][2]);
		}
		else if (heightMap[i][0] < left && heightMap[i][1] >= left && heightMap[i][1] <= right){
			ret.push_back(make_pair(heightMap[i][0], heightMap[i][2]));
			left = heightMap[i][0];
			fillGap(ret, gap, heightMap[i][0], heightMap[i][1], heightMap[i][2]);
		}
		else if (heightMap[i][0] >= left && heightMap[i][0] <= right && heightMap[i][1] > right){
			ret.push_back(make_pair(right, heightMap[i][2]));
			right = heightMap[i][1];
			fillGap(ret, gap, heightMap[i][0], heightMap[i][1], heightMap[i][2]);
		}
		else if (heightMap[i][0] < left && heightMap[i][1] > right){
			ret.push_back(make_pair(heightMap[i][0], heightMap[i][2]));
			ret.push_back(make_pair(right, heightMap[i][2]));
			left = heightMap[i][0];
			right = heightMap[i][1];
			fillGap(ret, gap, heightMap[i][0], heightMap[i][1], heightMap[i][2]);
		}
		else{
			ret.push_back(make_pair(heightMap[i][0], heightMap[i][2]));
			if (heightMap[i][1] < left){
				gap.push_back(make_pair(heightMap[i][1], left));
				left = heightMap[i][0];
			}
			else if (heightMap[i][0] > right){
				gap.push_back(make_pair(right, heightMap[i][0]));
				right = heightMap[i][1];
			}
			
		}

	}

	for (int i = 0; i < gap.size(); i++){
		ret.push_back(make_pair(gap[i].first, 0));
	}
	ret.push_back(make_pair(right, 0));
	sort(ret.begin(), ret.end());
	auto it = ret.begin();
	int current = INT_MIN;
	while (it != ret.end()){
		if (it->second == current){
			ret.erase(it);
		}
		else
			it++;
	}
	return ret;
	
	
}