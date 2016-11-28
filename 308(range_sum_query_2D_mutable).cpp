#include "leetcode.h"

class NumMatrix {
	vector<vector<int>> m_matrix;
	vector<vector<int>> m_BITree;
	vector<vector<int>> m_STree;
	vector<int> m_size;

	void constructSTree(vector<int> &row, vector<int> &tree);
	void constructSTreeHelper(vector<int> &row, vector<int> &tree, int left, int right, int index);
	void updateSTree(int index, vector<int> &tree, int val);
	void updateSTreeHelper(vector<int> &tree, int updateIndex, int left, int right, int val, int index);
	int getSumSTree(vector<int> &tree, int left, int right);
	int getSumSTreeHelper(vector<int> &tree, int left, int right, int ql, int qr, int index);

	void constructBITree(vector<int> &row, vector<int> &tree);
	void updateBITree(int index, vector<int> &tree, int val);
	int getSumBITree(vector<int> &tree, int index);
public:
	NumMatrix(vector<vector<int>> &matrix);
	void update(int row, int col, int val);
	int sumRegion(int row1, int col1, int row2, int col2);
};

NumMatrix::NumMatrix(vector<vector<int>> &matrix){
	m_matrix = matrix;
	for (int i = 0; i < matrix.size(); i++){
		m_BITree.push_back(vector<int>(matrix[i].size() + 1, 0));
		int size = 2 * pow(2, ceil(log2(matrix[i].size()))) - 1;
		m_STree.push_back(vector<int>(size, 0));
		constructBITree(matrix[i], m_BITree[i]);
		constructSTree(matrix[i], m_STree[i]);
		m_size.push_back(matrix[i].size());
	}
}

void NumMatrix::constructSTree(vector<int> &row, vector<int> &tree){
	constructSTreeHelper(row, tree, 0, row.size() - 1, 0);
}

void NumMatrix::constructSTreeHelper(vector<int> &row, vector<int> &tree, int left, int right, int index){

	if (left == right){
		tree[index] = row[left];
		return;
	}

	int mid = left + (right - left) / 2;
	constructSTreeHelper(row, tree, left, mid, index * 2 + 1);
	constructSTreeHelper(row, tree, mid + 1, right, index * 2 + 2);
	tree[index] = tree[index * 2 + 1] + tree[index * 2 + 2];

}

void NumMatrix::updateSTree(int index, vector<int> &tree, int val){
	updateSTreeHelper(tree, index, 0, m_size[0] - 1, val, 0);
}

void NumMatrix::updateSTreeHelper(vector<int> &tree, int updateIndex, int left, int right, int val, int index){


	if (left > updateIndex || updateIndex > right){
		return;
	}

	tree[index] += val;
	if (left != right){
		int mid = left + (right - left) / 2;
		updateSTreeHelper(tree, updateIndex, left, mid, val, index * 2 + 1);
		updateSTreeHelper(tree, updateIndex, mid + 1, right, val, index * 2 + 2);
	}

}

int NumMatrix::getSumSTree(vector<int> &tree, int left, int right){
	return getSumSTreeHelper(tree, 0, m_size[0] - 1, left, right, 0);
}

int NumMatrix::getSumSTreeHelper(vector<int> &tree, int left, int right, int ql, int qr, int index){
	if (left > right || ql > right || qr < left){
		return 0;
	}
	else if (ql <= left && qr >= right){
		return tree[index];
	}
	else{
		int mid = left + (right - left) / 2;
		return getSumSTreeHelper(tree, left, mid, ql, qr, index * 2 + 1) + getSumSTreeHelper(tree, mid + 1, right, ql, qr, index * 2 + 2);
	}
}

void NumMatrix::constructBITree(vector<int> &row, vector<int> &tree){
	for (int i = 0; i < row.size(); i++){
		updateBITree(i, tree, row[i]);
	}
}

void NumMatrix::updateBITree(int index, vector<int> &tree, int val){
	index = index + 1;
	while (index < tree.size()){
		tree[index] += val;
		index += index & (-index);
	}
}

int NumMatrix::getSumBITree(vector<int> &tree, int index){
	index = index + 1;
	int sum = 0;
	while (index > 0){
		sum += tree[index];
		index -= index & (-index);
	}
	return sum;
}

void NumMatrix::update(int row, int col, int val){
	int difference = val - m_matrix[row][col];
	m_matrix[row][col] = val;
	updateBITree(col, m_BITree[row], difference);
	updateSTree(col, m_STree[row], difference);
}

int NumMatrix::sumRegion(int row1, int col1, int row2, int col2){
	int totalBITree = 0;
	int totalSTree = 0;
	for (int i = row1; i <= row2; i++){
		int end = getSumBITree(m_BITree[i], col2);
		int begin = col1 == 0 ? 0 : getSumBITree(m_BITree[i], col1 - 1);
		totalBITree += (end - begin);
		totalSTree += getSumSTree(m_STree[i], col1, col2);
	}
	cout << "STree: " << totalSTree << endl << "BITree: " << totalBITree << endl;
	return totalSTree;
}
