#include "leetcode.h"

void integerReplacement2(int n, int &minimum, int counter){

	if (n == 1){
		minimum = min(counter, minimum);
		return; 
	}

	if (n & 1){
		integerReplacement2(n + 1, minimum, counter + 1);
		integerReplacement2(n - 1, minimum, counter + 1);
	}
	else{
		integerReplacement2(n / 2, minimum, counter + 1);
	}

}


int Solution::integerReplacement(int n){

	int min = INT_MAX;
	int counter = 0;
	integerReplacement2(n, min, counter);
	return min; 
}