/*
CTCI problem 7 - chapter 4
*/

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* parent;
  vector <TreeNode*> children;
  TreeNode(int x) : val(x), parent(NULL), children({}) {}
};
