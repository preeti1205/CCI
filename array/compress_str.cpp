/* CLRS array prob 6 */
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  string input, compressed;
  cout << "Enter the string : ";
  cin >> input;
  int len = input.size();
  int counter = 0;

  for(int i = 0; i < len ; i++) {
    counter++;
    if ( (input[i] != input[i + 1]) || (i + 1 == len) ) {
      compressed += input[i] + to_string(counter);
      counter = 0;
    }
  }

  if (compressed.size() > len) cout << input << endl;
  else cout << compressed << endl;
  return 0;
}
