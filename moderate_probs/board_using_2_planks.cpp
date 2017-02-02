/*
You are given infinite planks of only 2 sizes. You have to 
build a diving board by connecting planks from end-to-end.
Print all the different lengths boards you can make 
using exactly k planks
*/

#include <iostream>
#include <iomanip>
using namespace std;

Class Solution{
public:
	// backtracking - O(2^k) 
	void planks(int sum, int count, int shorter, int longer, set<int> &result) {
		if (count == 0)
			result.insert(sum);

		planks(sum + shorter, count - 1, shorter, longer, result);
		planks(sum + longer, count - 1, shorter, longer, result);
	}

	//memoization O(K*K)
	void plank_memo(int sum, int count, int shorter, int longer, unordered_map<string, int> &cache, set<int> &result) {
		string str = string(sum + count);
		if(cache.find(str) != cache.end()) return;
		if(count == 0) {
			result.insert(sum);
			return;
		}
		cache.insert(make_pair(str, 1));

		plank_memo(sum + shorter, count - 1, shorter, longer, cache);
		plank_memo(sum + longer, count - 1, shorter, longer, cache);
	}

	vector<int> plank_linear(int k, int shorter, int longer) {
		vector<int> result;

		for(int i = 0; i <= k; i++) {
			int sum = i*(shorter) + (k - i)*longer;
			result.insert(sum);
		}
		return result;
	}

};