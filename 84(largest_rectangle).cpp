#include"leetcode.h"



int Solution::largestRectangleArea(vector<int>& heights){
	
	if (heights.empty()){
		return 0;
	}

	stack<int> indexStack;
	int maxArea = INT_MIN;
	int i;
	for (i = 0; i != heights.size(); i++){

		if (indexStack.empty() || heights[i] >= heights[indexStack.top()]){
			indexStack.push(i);
		}
		else{
			while (!indexStack.empty() && heights[i] < heights[indexStack.top()]){

				int top = indexStack.top();
				indexStack.pop();

				if (indexStack.empty()){
					int area = heights[top] * i;
					if (area > maxArea){
						maxArea = area;
					}
				}
				else{
					int area = (i - indexStack.top() - 1) * heights[top];
					if (area > maxArea){
						maxArea = area;
					}
				}
			}
			indexStack.push(i);
		}
		
	}

	while (!indexStack.empty()){

		int top = indexStack.top();
		indexStack.pop();

		if (indexStack.empty()){
			int area = heights[top] * i;
			if (area > maxArea){
				maxArea = area;
			}
		}
		else{
			int area = (i - indexStack.top() - 1) * heights[top];
			if (area > maxArea){
				maxArea = area;
			}
		}
	}

	
	return maxArea;

}