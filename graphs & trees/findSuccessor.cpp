/*
CTCI problem 4 - chapter 6
*/

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode* parent;
  TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution{
public:
  TreeNode* findSuccessor(TreeNode* root) {
    if (root->right) {   //if TreeNode has a right child
      TreeNode* temp = root->right;
      while(temp->left) {
        temp = temp->left;
      }
      return temp;
    }

    if (root == root->parent->left) //if TreeNode is the left child
      return root->parent;

    while(root) {      //if TreeNode is the right Child or has no right child
      root = root->parent;
      if(root == root->parent->left)
        return root->parent;
    }
    return root;
  }

  TreeNode* makeTree(vector<int> &input, int start, int end) {
    if (start > end)
      return NULL;

    int mid = (start + end)/2;
    TreeNode* root = new TreeNode(input[mid]);
    root->left = makeTree(input, start, mid - 1);
    root->right = makeTree(input, mid + 1, end);
    root->left->parent = root;
    root->right->parent = root;
    return root;
  }
};

int main() {
  int n;
  vector<int> input;
  Solution sol;
  cout << "Enter the number of nodes : ";
  cin >> n;
  cout << "Enter the values : ";
  for(int i = 0; i < n; i++) {
    int num;
    cin >> num;
    input.push_back(num);
  }
  /*
  TreeNode* root = sol.makeTree(input, 0, n - 1);
  root->parent = NULL;
  TreeNode* successor = sol.findSuccessor(root->left);
  cout << successor->val << endl;
  */
  return 0;
}
