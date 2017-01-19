/*
CTCI problem 4 - chapter 5
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
  bool isBST(ListNode* root) {
    if (root == NULL) return true;
    int left_val = root->left->val;
    int right_val = root->right->val;
    int root_val = root->val;
    if ( (left_val > root_val) || (root_val > right_val)) return false;
    bool isLeft = isBST(root->left);
    bool isRight = isBST(root->right);

    return (isLeft && isRight);
  }
};
