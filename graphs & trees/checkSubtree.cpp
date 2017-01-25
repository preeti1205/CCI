/*
CTCI graph problem 10
*/

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  findMatches(TreeNode* root, TreeNode* t2, vector <TreeNode* > &result) {
      if (root == NULL) return;
      if(root->val == t2->val) result.push_back(root);

      findMatches(root->left, t2, result);
      findMatches(root->right, t2, result);
  }

  bool checkMatches(TreeNode* t2, TreeNode* candi) {
    if (t2 == NULL) return true;        //assuming that t2 is not an exact match till the end
    if (candi == NULL) return false;   //if it was to be an exact match t2== NULL || candi == NULL will return false;
    if (t2->val != candi->val) return false;

    bool left_val = checkMatches(t2->left, candi->left);
    if (left_val == false) return false;

    return (left_val && checkMatches(t2->right, candi->right));

  }
};
