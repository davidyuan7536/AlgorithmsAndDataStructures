#include "leetcode.h"

double Solution::powerxn(int x, int n){
	if (n == INT_MIN){
		if (x == 1 || x == -1){
			return 1;
		}
		else
			return 0.0;
	}

	if (n == 0){
		return 1;
	}
	if (n == 1){
		return x;
	}

	if (n < 0){
		x = 1 / x;
		n = -n;
	}


	if (n % 2 != 0){
		return x * powerxn(x*x, (n - 1) / 2);
	}
	else{
		return powerxn(x*x, n / 2);
	}

}