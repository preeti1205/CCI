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

class Solution {
public:
  void build_graph(vector<char> projects, vector<pair<char, char> > depend) {
    int n = depend.size();
    unordered_map<char, vector<char> > graph;
    unordered_map<char, int> visited_children;
    for(int i = 0; i < n; i++) {
        auto it = depend[i];
        if (graph.find(it.first) != graph.end()){
            graph[it.first].push_back(it.second);
        }
        else graph[it.first] = {it.second};
        visited_children[it.second]++;
    }
  }
};
