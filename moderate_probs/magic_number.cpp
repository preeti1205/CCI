/*

*/

#include <iomanip>
#include <iostream>
using namespace std;

class Solution {
public:
  int magic_distinct(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    int mid = 0;
    int result = -1;

    while(start <= end) {
      mid = (start + end) / 2;
      if (mid == arr[mid]) return mid;
      if (mid < arr[mid]) end = mid - 1;
      else start = mid + 1;
    }

    return result;
}
int magic_non_distinct(int arr[], int n) {
  int start = 0;
  int end = n - 1;
  int mid = 0;
  int result = -1;

  while(start <= end) {
    mid = (start + end) / 2;
    if (mid == arr[mid]) return mid;
    if (mid < arr[mid]) end = min(mid - 1, arr[mid]);
    else start = max(mid + 1, arr[mid]);
  }

  return result;
}
};

int main() {
  int n;
  cout << "enter number of elements :";
  cin >> n;
  int arr[n];
  cout << "Enter the elements: ";
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[i] = num;
  }
  sort(arr, arr + n);

  int result = magic_distinct(arr, n);
  return 0;
}
