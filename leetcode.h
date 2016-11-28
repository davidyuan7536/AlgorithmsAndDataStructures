#ifndef LC368_H
#define LC368_H

#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<numeric>
#include<string>


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}

};

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}

};


class Codec2 {

public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root);
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data);
};


class Solution {

public:
	int longestSubstringWithoutRepeatingCharacters(string s);
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);
	string intToRomanNumeral(int x);
	int romanNumeralToInt(string x);
	vector<vector<int>> threeSums(vector<int> & num);
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	ListNode* mergeKLists(vector<ListNode*>& lists);
	int searchInRotatedSortedArray(vector<int>& nums, int target);
	string countAndSay(int n);
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target);
	vector<vector<int>> permute(vector<int>& nums);
	vector<vector<string>> groupAnagrams(vector<string>& strs);
	double powerxn(int x, int n);
	int maxSubArray(vector<int>& nums);
	bool canJump(vector<int>& nums);
	string getPermutation(int n, int k);
	ListNode* rotateRight(ListNode* head, int k);
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);
	int minDistance(string word1, string word2);
	void setZeroes(vector<vector<int>>& matrix);
	bool searchMatrix(vector<vector<int>>& matrix, int target);
	string minWindow(string s, string t);
	bool exist(vector<vector<char>>& board, string word);
	int largestRectangleArea(vector<int>& heights);
	string addStrings(string num1, string num2);
	bool canPartition(vector<int>& nums);
	int splitArray(vector<int>& nums, int m);
	bool isScramble(string s1, string s2);
	vector<int> grayCode(int n);
	bool isInterleave(string s1, string s2, string s3);
	int numDistinct(string s, string t);
	int minimumTotal(vector<vector<int>>& triangle);
	int maxProfit(vector<int>& prices);
	int numDecodings(string s);
	bool canCross(vector<int>& stones);
	int maxEnvelopes(vector<pair<int, int>>& envelopes);
	vector<int> countSmaller(vector<int>& nums);
	int minPatches(vector<int>& nums, int n);
	void wiggleSort(vector<int>& nums);
	void sortColors(vector<int>& nums);
	string decodeString(string s);
	int numIslands(vector<vector<char>>& grid);
	vector<int> topKFrequent(vector<int>& nums, int k);
	int numSquares(int n);
	vector<string> findStrobogrammatic(int n);
	bool isRectangleCover(vector<vector<int>>& rectangles);
	int longestIncreasingPath(vector<vector<int>>& matrix);
	string minAbbreviation(string target, vector<string>& dictionary);
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);
	vector<Interval> insertInterval(vector<Interval>& intervals, Interval newInterval);
	vector<string> generateAbbreviations(string word);
	int longestConsecutive(vector<int>& nums);
	ListNode* plusOne(ListNode* head);
	string removeKdigits(string num, int k);
	int integerReplacement(int n);
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges);
	int getMoneyAmount(int n);
	vector<string> wordBreak(string s, unordered_set<string>& wordDict);
	vector<string> addOperators(string num, int target);
	string shortestPalindrome(string s);
	int kthSmallest(vector<vector<int>>& matrix, int k);
	int countNumbersWithUniqueDigits(int n);
	bool isReflected(vector<pair<int, int>>& points);
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k);
	bool validTree(int n, vector<pair<int, int>>& edges);
	vector<vector<int>> verticalOrder(TreeNode* root);
	int nthSuperUglyNumber(int n, vector<int>& primes);
	int maxCoins(vector<int>& nums);
	bool validWordSquare(vector<string>& words);
	int findMaximumXOR(vector<int>& nums);
	bool isValidSerialization(string preorder);
	vector<string> binaryTreePaths(TreeNode* root);
	string frequencySort(string s);
	string removeDuplicateLetters(string s);
	int combinationSum4(vector<int>& nums, int target);
	int maxProfit2(vector<int>& prices);
	int minMeetingRooms(vector<Interval>& intervals);
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions);
	bool isMatch(string s, string p);
	int minArea(vector<vector<char>>& image, int x, int y);
	vector<string> letterCombinations(string digits);
	int threeSumSmaller(vector<int>& nums, int target);
	int numberOfPatterns(int m, int n);
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries);
	void wallsAndGates(vector<vector<int>>& rooms);
	int trap(vector<int>& height);
	void nextPermutation(vector<int>& nums);
	void gameOfLife(vector<vector<int>>& board);
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people);
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings);
	int trapRainWater(vector<vector<int>>& heightMap);
	int maxProduct(vector<string>& words);
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k);
	vector<TreeNode*> generateTrees(int n);
	bool isStrobogrammatic(string num);
	void connect(TreeLinkNode *root);
	void connect2(TreeLinkNode *root);
	vector<int> rightSideView(TreeNode* root);
	void recoverTree(TreeNode* root);
	int maximumGap(vector<int>& nums);
	vector<string> removeInvalidParentheses(string s);
	int lengthLongestPath(string input);
	int lengthOfLongestSubstringKDistinct(string s, int k);
	int wordsTyping(vector<string>& sentence, int rows, int cols);
	int maxKilledEnemies(vector<vector<char>>& grid);
	int longestConsecutive(TreeNode* root);
	vector<string> findMissingRanges(vector<int>& nums, int lower, int upper);
	vector<vector<string>> wordSquares(vector<string>& words);
	bool validUtf8(vector<int>& data);
	int shortestDistance(vector<vector<int>>& grid);
	vector<Interval> mergeInterval(vector<Interval>& intervals);
	vector<int> largestDivisibleSubset(std::vector<int>&nums);
	int sumOfTwoIntegers(int a, int b);
	int lengthOfLongestSubstringTwoDistinct(string s);
	vector<string> summaryRanges(vector<int>& nums);
	vector<string> readBinaryWatch(int num);
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList);
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix);
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
};






#endif