#include <iostream>
#include <iomanip>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool isUnique(string input) {
    int len = input.size();
    if (len == 0) return true; //assuming unique is true for an empty string. Ask for clarification.
    unordered_map<char, int> dict;

    for(int i = 0; i < len; i++) {
      if(dict.find(input[i]) != dict.end()) {
        return false;
      }
      dict[input[i]]++;
    }

    return true;
  }

  bool isUniqueWithoutMap(string input) {
    int len = input.size();
    sort(input.begin(), input.end()); //if altering the string is allowed. No prob here as it is being passed by value
                                      //runs for empty string as well
    for(int i = 1; i < len; i++) {
      if(input[i] == input[i - 1]) return false;
    }
    return true;
  }
};

int main() {
  string input;
  Solution sol;
  cout << "Enter the string input: ";
  cin >> input;
  cout << sol.isUniqueWithoutMap(input)<<endl;
  return 0;
}
