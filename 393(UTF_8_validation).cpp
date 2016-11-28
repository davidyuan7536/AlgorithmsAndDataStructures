#include "leetcode.h"


string convertToBinary(int data){

	string ret; 
	while (data > 0){
		ret += to_string(data % 2);
		data /= 2; 
	}
	while (ret.length() < 8){
		ret += '0';
	}
	reverse(ret.begin(), ret.end());
	return ret; 
}


bool Solution::validUtf8(vector<int>& data){

	int mask = 255;
	int len{ 0 };
	for (int i = 0; i < data.size(); i++){

		data[i] &= mask;
		string binary = convertToBinary(data[i]);

		if (len != 0){
			if (binary[0] != '1' || binary[1] != '0')
				return false;
			else{
				len--;
				if (len == 1){
					len = 0;
				}
				continue;
			}
				
		}

		for (int j = 0; j < 4 && binary[j] != '0'; j++){
			len++;
		}
		

	}

	if (len != 0){
		return false;
	}
	return true;
}