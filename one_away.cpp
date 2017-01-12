#include <iomanip>
#include <iostream>
#include <math.h>
using namespace std;

int main() {
  string s1, s2;
  cout << "Enter string 1: ";
  getline(cin, s1);
  cout << "Enter string 2: ";
  getline(cin, s2);
  int len1 = s1.size();
  int len2 = s2.size();
  if (s1 == s2) return true;
  if( abs(len1 - len2) > 1) return false;

  int i = len1 - 1, j = len2 - 1;
  int edits = 0;
  while(i >= 0 && j >= 0) {
    if (s1[i] == s2[j]){
      i--; j--;
    }
    else {
      if (i == j) {
        i--;
        j-- ;
      }
      else if (i > j) i--;
      else j--;
      edits++;
    }
    if (edits > 1) {
      break;
    }
  }
  edits += max(i + 1, j + 1);

  cout << (edits < 2) << endl;
  return 0;

}
