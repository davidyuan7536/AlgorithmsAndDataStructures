#include "leetcode.h"

int Solution::wordsTyping(vector<string>& sentence, int rows, int cols){

	string str = "";
	for (string& s : sentence)
		str += s + ' ';
	int count = 0, n = str.size();
	while (rows--) {
		count += cols;
		if (str[count % n] == ' ') count++;
		else {
			while (count % n && str[count % n - 1] != ' ')
				count--;
		}
	}
	return count / n;

}