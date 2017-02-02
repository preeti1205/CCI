/*
CTCI prob 13 - graphs
*/

#include <iomanip>
#include <iostream>
using namespace std;

class Solution {
public:
  void total_paths_with_sum(TreeNode* root, int target_sum, int &counter) {
    //if (target_sum < 0) return;
    if(root == NULL) return;
    if (target_sum == root->val) {
      count++;
    }
    
    int curr_val = root->val;
    (root->left, target_sum - curr_val, counter);
    (root->right, target_sum - curr_val, counter);
    (root->left, target_sum, counter);
    (root->right, target_sum, counter);

  }

};
