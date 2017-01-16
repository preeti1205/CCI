/* CTCI problem 2 in chapter 4*/
#include <iomanip>
#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* left;
  ListNode* right;
  ListNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  ListNode* BSTify(int arr[], int start, int fin) {
    if (start > fin)
      return NULL;
    int mid = (start + fin) / 2;
    ListNode* root = new ListNode(arr[mid]);
    root->left = BSTify(arr, start, mid - 1);
    root->right = BSTify(arr, mid + 1, fin);
    return root;
  }
};

int main() {
  Solution sol;
  int n, num;
  cout << "Enter the size of array: ";
  cin >> n;
  int arr[n];
  cout << "Enter array elements: ";
  for(int i = 0; i < n; i++) {
    cin >> num;
    arr[i] = num;
  }
  ListNode* result = sol.BSTify(arr, 0, n - 1);
  cout << result->val << endl;

  return 0;
}
