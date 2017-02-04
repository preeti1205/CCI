/*
Recursion
*/

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Solution {
public:
	int findTargetIndex(int start, int end, vector<int> nums, int target){
		if(target < nums[start] || target > nums[end]) return -1;
		if(nums[start] == target) return start;
		int mid = 0;
		while(start < end) {
			mid = (start + end) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] > target) end = mid -1;
			else start = mid + 1;
		}
		return -1;
	}
	int findRange(vector<int> nums, int target) {
		if (nums[0] == target) return 0;
		int start = 1;
		int end = 2;
		while(nums[end] < target && nums[end] != -1) {
			if (nums[start] > target ) return -1;
			start = end + 1;
			end = 2*start;
		}
		if(nums[start] == -1 && nums[end] == -1) return -1;
		while(nums[end] == -1) end--;
		return findTargetIndex(start, end, nums, target);
	}
};