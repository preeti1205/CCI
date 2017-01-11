/* CTCI array prob 3 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  string input;
  int len;
  int spaces = 0, count = 0;
  cout << "Enter input string: ";
  getline(cin, input);
  cout << "Enter length: ";
  cin >> len;
  int orig_len = input.size();
  for(int i = 0; i < len; i++) {
    if (input[i] == ' ') spaces++;
  }
  cout << "Number of spaces : " << spaces << endl;
  for(int i = len - 1; i >= 0 && spaces > 0; i--) {
    if (input[i] != ' ' ) {               //(input[i] != ' ' && spaces != 0)
      input[ i + 2*spaces ] = input[i];
      input[i] = ' ';
    }
    else spaces--;                        //else if (input[i] == ' ') spaces--;
  }
  cout << "new string: " << input << endl;
  for(int i = 0; i < orig_len; i++) {
    if (input[i] != ' ') continue;
    if (input[i] == ' ') {
      if (count == 0) input[i] = '%';
      if (count == 1) input[i] = '2';
      if (count == 2) input[i] = '0';
      count++;
    }
    count = count%3;
  }
  cout << input << endl;
  return 0;
}
