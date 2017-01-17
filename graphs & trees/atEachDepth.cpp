/*
CTCI chapter 4 problem 3
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
  void atEachDepth_recursive(ListNode* root, int depth, unordered_map<int, vector< ListNode* > > &result) {
    if (root == NULL)
      return ;
    if(result.find(depth) != result.end()) {
      result[depth].push_back(root);
    }
    else
      result[depth] = root;
    if (root-> left)
      atEachDepth_recursive(root->left, depth + 1, result);
    if (root ->right)
      atEachDepth_recursive(ROOT->right, depth + 1, result);

  }

  void atEachDepth_iterative(ListNode* root, int depth, unordered_map<int, vector< ListNode* > > &result) {
    if (root == NULL)
      return ;
    queue<ListNOde* > cache;
    cache.insert(root);
    int depth = 0;
    while(cache) {
      int n = cache.size();
      for(int i = 0; i < n; i++) {
        ListNode* temp = cache.front();
        cache.pop();
        if (result.find(depth) != result.end())
            result[depth].push_back(temp);
        else {
          result[depth] = {};
          result[depth].push_back(temp);
        }
        if(temp->left) cache.push_back(temp->left);
        if(temp->right) cache.push_back(temp->right);
      }
      depth++;
    }
    }
};
