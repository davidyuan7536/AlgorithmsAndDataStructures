#include "leetcode.h"


int factorial(int n)
{
	return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

string Solution::getPermutation(int n, int k){
	vector<char> availableChars;
	for (int i = 0; i < n; i++)
	{
		availableChars.push_back('1' + i);
	}

	string result;
	k--;

	for (int i = 0; i < n; i++)
	{
	
		int idx = k / factorial(n - i - 1);

	
		result.push_back(availableChars[idx]);

		
		availableChars.erase(availableChars.begin() + idx);

		k %= factorial(n - i - 1);
	}

	return result;
}