#include "leetcode.h"

int Solution::countNumbersWithUniqueDigits(int n){
	vector<int> tbl(min(n, 10) + 1, 1);
	for (int i = 1; i <= min(n, 10); i++)
		tbl[i] = tbl[i - 1] * (i == 1 ? 9 : (9 - i + 2));
	return accumulate(tbl.begin(), tbl.end(), 0);
}