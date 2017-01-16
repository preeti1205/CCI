/* CLRS array prob 9 */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class Solution {
public:
  void rotate(vector<vector<int> > &input) {
    int n_rows = input.size();
    int n_cols = input[0].size();
    bool zeroFRow = false, zeroFCol = false;
    for(int i = 0; i < n_cols; i++) {
      if (input[0][i] == 0) {
        zeroFRow = true;
        break;
      }
    }

    for(int i = 0; i < n_rows; i++) {
      if (input[0][i] == 0) {
        zeroFCol = true;
        break;
      }
    }

    for(int i = 1; i < n_rows; i++) {
      for(int j = 1; j < n_cols; j++){
        if (input[i][j] == 0) {
          input[0][j] = 0;
          input[i][0] = 0;
        }
      }
    }

    for(int i = 1; i < n_cols; i++) {
      for(int j = 1; j < n_rows && input[0][i] == 0; j++)
        input[j][i] = 0;
    }

    for(int i = 1; i < n_rows; i++) {
      for(int j = 1; j < n_cols && input[i][0] == 0; j++)
        input[i][j] = 0;
    }
    if(zeroFRow) {
      for(int i = 0; i < n_cols; i++) input[0][i] = 0;
    }

    if(zeroFCol) {
      for(int i = 0; i < n_rows; i++) input[i][0] = 0;
    }
  }
};

int main(){
  vector<vector<int> > input;
  Solution sol;
  cout << "Enter the matrix";
  int inp;
  for(int i = 0; i < 3; i++) {
    vector<int> temp;
    for(int j = 0; j < 3; j++) {
      cin>>inp;
      temp.push_back(inp);
    }
    input.push_back(temp);
  }

  sol.rotate(input);

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      cout << input[i][j] << " ";
    }
    cout << endl;
  }
  return 0;

}
