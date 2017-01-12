/* CLRS array prob 7 */
#include <iostream>
#include <iomanip>
using namespace std;
class Solution {
public:
  void rotate(vector<vector<int> > &input) {
    int n = input.size();  //coz rows and columns are equal
    for(int layer = 0; layer < (n/2); layer++) {
      int first = layer;
      int last = n - 1 - first;
      for (int col = first; col < last; col++) {
        int offset = i - first;
        int temp = input[first][col];
        input[first][col] = input[last - offset][first];
        input[last - offset][first] = input[last][last - offset];
        input[last][last - offset] = input[i][last];
        input[i][last] = temp;
      }
    }
  }
};

int main(){
  
}
