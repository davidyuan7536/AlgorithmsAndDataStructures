#include "leetcode.h"

int Solution::sumOfTwoIntegers(int a, int b){

	if (b == 0)
		return a;

	int sum;
	int carry;
	sum = a ^ b;
	carry = (a&b) << 1;
	return sumOfTwoIntegers(sum, carry);

}