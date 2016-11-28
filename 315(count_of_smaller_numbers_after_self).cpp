#include "leetcode.h"


struct myNode{

	int val;
	int smaller; 
	myNode * left;
	myNode * right;
	myNode(int value){
		val = value;
		smaller = 0;
		left = right = nullptr;
	}

};


int insert(myNode *&head, int val){

	if (head == nullptr){
		head = new myNode(val);
		return 0;
	}

	if (val <= head->val){
		head->smaller++;
		return insert(head->left, val);
	}
	else{
		return 1 + head->smaller + insert(head->right, val);
	}
}

vector<int> Solution::countSmaller(vector<int>& nums){

	if (nums.empty()){
		return vector<int>{};
	}
	if (nums.size() == 1){
		return vector<int>{0};
	}

	myNode * head = nullptr;
	deque<int> myDeque;
	for (int i = nums.size()-1; i >= 0; i--){
		int temp = insert(head, nums[i]);
		myDeque.push_front(temp);
		cout << temp << " ";
	}
	cout << endl;
	return vector<int>(myDeque.begin(), myDeque.end());

}

/*
pair<pair<int, int>, int> segmentTree(vector<int> & nums, vector<pair<pair<int, int>, int>> &st, int left, int right, int pos){

	if (right < left){
		return make_pair(make_pair(0,0),0);
	}

	if (right == left){	
		st[pos] = make_pair(make_pair(nums[left], nums[left]), 1);
		return st[pos];
	}

	int mid = left + (right - left) / 2;
	pair<pair<int, int>, int> l = segmentTree(nums, st, left, mid, pos * 2 + 1);
	pair<pair<int, int>, int> r = segmentTree(nums, st, mid+1, right, pos * 2 + 2);
	st[pos] = make_pair(make_pair(max(l.first.first, r.first.first), min(l.first.second, r.first.second)), l.second + r.second);
	return st[pos];
}


int queryCountSmaller(vector<int>&nums, int it, vector<pair<pair<int, int>, int>> &st, int left, int right, int pos, int l, int r){

	if (l <= left && right <= r){
		if (nums[it] <= st[pos].first.first){
			
			if (nums[it] <= st[pos].first.second || st[pos].second <= 1){
				return 0;
			}

			int mid = left + (right - left) / 2;
			int resL = queryCountSmaller(nums, it, st, left, mid, pos * 2 + 1, l, r);
			int resR = queryCountSmaller(nums, it, st, mid + 1, right, pos * 2 + 2, l, r);
			return resL + resR; 
		}
		else{
			return st[pos].second;
		}
	}
	else if (r < left || right < l){
		return 0;
	}
	else{
		int mid = left + (right - left) / 2;
		int resL = queryCountSmaller(nums, it, st, left, mid, pos * 2 + 1, l, r);
		int resR = queryCountSmaller(nums, it, st, mid + 1, right, pos * 2 + 2, l, r);
		return resL + resR;
	}
}


vector<int> Solution::countSmaller(vector<int>& nums){

	vector<int> ret;
	if (nums.empty()){
		return ret;
	}
	if (nums.size() == 1){
		ret.push_back(0);
		return ret;
	}

	int n = 2 * pow(2.0, ceil(log2(nums.size()))) - 1;
	vector<pair<pair<int,int>, int>> st(n, make_pair(make_pair(0,0), 0));

	segmentTree(nums, st, 0, nums.size() - 1, 0);

	
	for (int i = 0; i < nums.size(); i++){
		ret.push_back(queryCountSmaller(nums, i, st, 0, nums.size() - 1, 0, i + 1, nums.size() - 1));

	}
	
	return ret;
}

*/