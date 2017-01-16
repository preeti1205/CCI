/* CTCI problem 1 in chapter 4*/
#include <iomanip>
#include <iostream>
using namespace std;

struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
  bool isReachable(UndirectedGraphNode* a, UndirectedGraphNode* b) {
    queue <UndirectedGraphNode*> cache;
    unordered_map<UndirectedGraphNode*, bool> visited;
    cache.push(a);

    while(cache) {
      auto temp = cache.front();
      cache.pop();
      if (temp == b) return true;

      int n = (temp->neighbors).size();
      for(int i = 0; i < n; i++) {
        UndirectedGraphNode* node = (temp->neighbors)[i];
        if (visited.find(node) != visited.end()) continue;
        else {
          visited[node] = true;
          cache.push(node);
        }
      }
    }
    return false;
  }
};
