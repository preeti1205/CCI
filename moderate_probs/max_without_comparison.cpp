/*
CTCI problem 7 - moderate problems
*/

#include <iomanip>
#include <iostream>
using namespace std;

class Solution {
public:
  int max_max(int a, int b) {
    int temp = a ^ b;
    int counter = 0;
    while(temp > 1) {
      counter++;
      temp >>= 1 ;
    }
    cout << counter << endl;
    //if (counter == 31) counter--;
    temp <<= counter;
    return (a & temp ? a: b);
  }
};

int main() {
  int a, b;
  Solution sol;
  cout << "Enter 2 integers :";
  cin >> a >> b;
  cout << "This is maxima: " << sol.max_max(a, b) << endl;

  return 0;
}
