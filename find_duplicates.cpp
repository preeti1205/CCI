/*
Sort problem 8
*/
class bitArray {
	//int totalNumbers;
	int arr[];
public:
	bitArray(int totalNumbers) {
		int x = totalNumbers / 32;
		arr = new int[x + 1];
	}
	int get(int y) {
		int wordNum = y/32;
		int bitNum = y % 32;
		return ((1 << bitNum) & arr[wordNum]);
	}
	void set(int y) {
		int wordNum = y/32;
		int bitNum = y % 32;
		arr[wordNum] = arr[wordNum] | (1 << bitNum);
	}

};

class Solution {
public:
	void checkDuplicates(vector<int> nums) {
		bitset bitArray(32000);
		int n = nums.size();
		for(int i = 0; i < n ; i++) {
			if (bitArray.get(nums[i]))
				cout << nums[i];
			else
				bitArray.set(nums[i]);
		}
	}
};