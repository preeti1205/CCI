/*
Given an array of sorted strings with empty strings in between
find the index of a given array
*/


#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution{
public:
	int findDirection(string target, string current) {
		if(target == current) return 0;
		int i = 0;
		while(target[i] == current[i]) i++;
		if (i == target.size()) return -1;
		else if (i == current.size()) return 1;

		return (target[i] - 'a' > current[i] - 'a' ? 1: -1);
	}

	int findStringIndex(vector<string> inputArray, string target) {
		int start = 0;
		int end = inputArray.size() - 1;
		int mid = 0;

		while(start < end) {
			mid = (start + end) / 2;
			if (inputArray[mid] == target)
				return mid;
			if (inputArray[mid].size() == 0) {
				int left = mid, right = mid;
				while(left >= start && inputArray[left].size() == 0) left--;
				while(right <= end && inputArray[right].size() == 0) right++;
				if(left < start && right > end) return -1;
				if (left < start) start = right;
				else if (right > end) end = left;
				else {
					int dir1 = findDirection(inputArray[left], target);
					int dir2 = findDirection(inputArray[right], target);
					if (dir1 == 0) return left;
					else if (dir2 == 0) return right;
					else if(dir1 == 1 && dir2 == 1) start = right + 1;
					else if (dir1 == -1 && dir2 == -1) end = left - 1;
					else return -1;
				}

			}
			else {
				int dir = findDirection(inputArray[mid], target);
				if (dir == -1) 
					end = mid - 1;
				else start = mid + 1;
			}
		}
		return start;
	}
};

int main() {
	vector<string> inputArray;
	Solution sol;
	string input, target;
	cout << "Enter the array of strings: ";
	getline(cin, input);
	stringstream buffer(input);
	string temp;
	while(getline(buffer, temp, ' ')){
		inputArray.push_back(temp);
	}
	cout << "The size is : " << inputArray.size() << endl;
	/*
	for(int i: inputArray {
		cout << inputArray[i] << endl;
	}
	*/
	cout << "Enter the target to find : ";
	cin >> target;
	cout << sol.findStringIndex(inputArray, target);
	return 0;
}