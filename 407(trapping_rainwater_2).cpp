#include "leetcode.h"

/*
struct compare
{
	bool operator()(const pair<int, pair<int, int>> & a, const pair<int, pair<int, int>> & b) const
	{
		return a.first > b.first; 
	}
};

int dfs(vector<vector<int>> & heightMap, vector<vector<int>> &visited, int x, int y){

	
	vector<int> directions{ 0, 1, 0, -1, 0 };
	visited[x][y] = 1;
	
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, compare> pq;

	for (int i = 0; i < 4; i++){
		int row = x + directions[i];
		int col = y + directions[i + 1];
		if (visited[row][col] == 0){
			pq.push(make_pair(heightMap[row][col], make_pair(row, col)));
		}
	}

	int searchResult = INT_MAX;
	while (!pq.empty() && searchResult > pq.top().first){
		
		pair<int, int> coords = pq.top().second;
		if (coords.first == 0 || coords.first == heightMap.size()-1 || coords.second == 0 || coords.second == heightMap[0].size()-1){
			searchResult = min(searchResult, heightMap[coords.first][coords.second]);
		}
		else{
			searchResult = min(searchResult, dfs(heightMap, visited, coords.first, coords.second));
			pq.pop();
		}
	}
	return max(searchResult, heightMap[x][y]);
}

int Solution::trapRainWater(vector<vector<int>>& heightMap){

	if (heightMap.size() < 3 || heightMap[0].size() < 3 ){
		return 0;
	}

	
	int ret = 0;
	int m = heightMap.size();
	int n = heightMap[0].size();

	for (int i = 1; i < m - 1; i++){
		for (int j = 1; j < n - 1; j++){
			vector<vector<int>> visited(m, vector<int>(n, 0));
			int search = dfs(heightMap, visited, i, j);
			if (search > heightMap[i][j]){
				ret += search - heightMap[i][j];
			}
		}
	}
	return ret;
}

*/


int Solution::trapRainWater(vector<vector<int>>& heightMap){

	if (heightMap.size() < 3 || heightMap[0].size() < 3){
		return 0;
	}

	int ret = 0;
	int m = heightMap.size();
	int n = heightMap[0].size();

	vector<vector<int>> waterMap(m, vector<int>(n, 0));
	int total = 0;

	for (int i = 1; i < m - 1; i++){
		for (int j = 1; j < n - 1; j++){

			waterMap[i][j] += 100000;
			total += 100000;
		}
	}

	bool spilled = true;
	while (spilled){
		spilled = false;
		for (int i = 1; i < m - 1; i++){
			for (int j = 1; j < n - 1; j++){
				if (waterMap[i][j] != 0){
					int currentHeight = waterMap[i][j] + heightMap[i][j];
					vector<int> directions{ 0, 1, 0, -1, 0 };
					for (int k = 0; k < 4; k++){
						int x = i + directions[k];
						int y = j + directions[k + 1];
						if (currentHeight > waterMap[x][y] + heightMap[x][y]){
							spilled = true;
							int spilledAmount = currentHeight - max(heightMap[i][j], waterMap[x][y] + heightMap[x][y]);
							currentHeight -= spilledAmount; 
							waterMap[i][j] -= spilledAmount;
							total -= spilledAmount;
						}
					}

				}
			}
		}
	}

	return total; 

}