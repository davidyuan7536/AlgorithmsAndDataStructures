#include "leetcode.h"

void readBinaryWatchHelper(vector<string> &ret, int hCur, int mCur, vector<int> &hourMask, vector<int> &minMask, int cur, int num){

	if (num == 0 ){	
		string temp = to_string(hCur) + ":";
		temp += mCur < 10 ? "0" + to_string(mCur) : to_string(mCur);
		ret.push_back(temp);
		return;
	}

	for (int i = cur; i < minMask.size() + hourMask.size(); i++){
		if (i < minMask.size()){
			mCur += minMask[i];
			if (mCur < 60){
				readBinaryWatchHelper(ret, hCur, mCur, hourMask, minMask, cur+1, num - 1);
			}
			mCur -= minMask[i];
		}
		else{
			hCur +=  hourMask[i - minMask.size()];
			if (hCur < 12){
				readBinaryWatchHelper(ret, hCur, mCur, hourMask, minMask, cur + 1, num - 1);
			}
			hCur -= hourMask[i - minMask.size()];
		}
		
	}



}


vector<string> Solution::readBinaryWatch(int num){

	vector<int> hourMask{ 1,2,4,8 };
	vector<int> minMask{ 1,2,4,8,16,32};
	vector<string> ret;
	readBinaryWatchHelper(ret, 0, 0, hourMask, minMask, 0, num);
	return ret;

}