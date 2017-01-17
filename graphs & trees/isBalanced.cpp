/*
CTCI chapter 4 problem 4
*/

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
  int findHeight(ListNode* root) {
    if(root == NULL) return 0;
    int left_height = findHeight(root->left);
    int right_height = findHeight(root->right);
    if (left_height == -1 || right_height == -1) return -1;
    if (abs(left_height - right_height) > 1) return -1;

    return 1 + max(left_height, right_height);
  }
};

int main() {
  //assuming a graph has node root
  int left = 0, right = 0;
  if(root == NULL) cout << true;
  if(root->left) left = findHeight(root->left);
  if(root->right) right = findHeight(root->right);
  if (left == -1 || right == -1) cout << false;
  else if (abs(left - right) > 1) cout << false;
  else cout << true;
  return 0;
}
