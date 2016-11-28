#include "leetcode.h"


void bfs(vector<vector<char>> &image, int x, int y, vector<int> &directions, int &minx, int &miny, int &maxx, int &maxy){

	image[x][y] = '2';

	minx = min(x, minx);
	maxx = max(x, maxx);
	miny = min(y, miny);
	maxy = max(y, maxy);

	for (int i = 0; i < 4; i++){
		int newX = x + directions[i];
		int newY = y + directions[i + 1];
		if (newX >= 0 && newX < image.size() && newY >= 0 && newY < image[0].size() && image[newX][newY] == '1'){
			bfs(image, newX, newY, directions, minx, miny, maxx, maxy);
		}
	}

}


int Solution::minArea(vector<vector<char>>& image, int x, int y){

	if (image.empty() || image[0].empty()){
		return 0;
	}

	int minx = INT_MAX;
	int miny = INT_MAX;
	int maxx = INT_MIN;
	int maxy = INT_MIN;
	vector<int> directions{ 0, 1, 0, -1, 0 };
	bfs(image, x, y, directions, minx, miny, maxx, maxy);

	return (maxx - minx + 1)*(maxy - miny + 1);
}