/* CTCI array prob 4 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  string input;
  int odd_counter = 0;
  int tally[128] = {};
  cout << "Enter the string: ";
  getline(cin, input);
  int len = input.size();

  for(int i = 0; i < len; i++) {
    if (isalpha(input[i])) tally[int(toupper(input[i]))]++;
    else if(isdigit(input[i])) tally[int(input[i])]++;
  }

  for(int i = 0; i < 128; i++) {
    if (tally[i] == 0) continue;
    int temp = tally[i]%2;
    if(temp == 1) odd_counter++;
    if (odd_counter > 1) {
      cout << false << endl;
      return 0;
    }
  }
  cout << true << endl;
  return 0;
}
