/*
stack of boxes piled on top of one another with biggest box at the bottom
*/

#include <iostream>
#include <iomanip>
using namespace std;

class box {
	int length;
	int breadth;
	int height;
}

class Solution {
public:
	int buildStack(int index, unordered_map<int, int> &cache, vector<box> &boxes) {
		int n = boxes.size();
		if (index == n) return 0;
		if (cache.find(index) != cache.end()) return cache[index];
		int maxHeight = 0;
		for(int i = index + 1; i < n; i++) {
			if (boxes[i].width < boxes[index].width &&
				boxes[i].length < boxes[index].length) {
				int temp = buildStack(i, cache, boxes);
				maxHeight = max(maxHeight, temp);
			}
		}
		cache[index] = maxHeight + boxes[index].height;
		return cache[index];  //TODO: why is return important?
	}

	int findMaxHeight(vector<box> boxes, int index) {
		//TODO: sort the boxes according to height
		vector<int> result;
		int n = boxes.size();
		unordered_map<int, int> cache;
		for(int i = 0;i < n; i++) {
			int boxMaxHeight = buildStack(i, cache, boxes);
			result.push_back(boxMaxHeight);
		}
		return *max_element(result.begin(), result.end());
	}

};

