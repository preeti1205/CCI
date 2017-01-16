#include <iomanip>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isPermuation(string input1, string input2) {
    if (input1 == input2) return true;
    int len1 = input1.size(), len2 = input2.size();
    if (len1 != len2) return false;
    int tally[128] = {};  //curly braces to initialize all elements with 0
    for(int i = 0; i < len1; i++) {
      tally[int(input1[i])]++;
      tally[int(input2[i])]--;
    }

    for(int i = 0; i < 128; i++) {
      if(tally[i] != 0) return false;
    }
    return true;
  }
};

int main() {
  string str1, str2;
  Solution sol;
  cout <<" Enter the two strings: ";
  cin >> str1 >> str2;
  cout << sol.isPermuation(str1, str2) << endl;
  return 0;
}
