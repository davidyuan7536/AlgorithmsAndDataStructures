#include "leetcode.h"

bool Solution::isInterleave(string s1, string s2, string s3){

	if (s1.length() + s2.length() != s3.length()){
		return false;
	}
	if (s3.length() != s1.length() + s2.length())
		return false;

	vector<vector<int>> table(s1.length() + 1, vector<int>(s2.length() + 1, 0));

	for (int i = 0; i<s1.length() + 1; i++)
		for (int j = 0; j< s2.length() + 1; j++){
			if (i == 0 && j == 0)
				table[i][j] = 1;
			else if (i == 0)
				table[i][j] = (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			else if (j == 0)
				table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
			else
				table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
	}

	return table[s1.length()][s2.length()];
	
}

bool isInterleave2(string s1, string s2, string s3){

	if (s1.length() + s2.length() != s3.length()){
		return false;
	}
	int it1 = 0;
	int it2 = 0;
	for (int i = 0; i < s3.length(); i++){



		if (s1[it1] == s2[it2] && s3[i] == s1[it1]){

			return isInterleave2(s1.substr(it1 + 1, s1.length() - it1), s2.substr(it2, s2.length() - it2), s3.substr(i + 1, s3.length() - i))
				|| isInterleave2(s1.substr(it1, s1.length() - it1), s2.substr(it2 + 1, s2.length() - it2), s3.substr(i + 1, s3.length() - i));

		}
		else if (s3[i] == s1[it1]){
			it1++;
		}
		else if (s3[i] == s2[it2]){
			it2++;
		}
		else{
			return false;
		}
	}
	return true;


}