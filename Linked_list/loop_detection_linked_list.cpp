/* CTCI linked list problem 8 */

#include <iomanip>
#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* isLoop(ListNode* l1) {
    ListNode* fast = l1;
    ListNode* slow = l1;

    while(fast != slow) {
      fast = fast->next->next;
      slow = slow->next;
    }

    ListNode* starter = l1;

    while(slow != starter) {
      starter = starter->next;
      slow = slow->next;
    }

    return starter;
  }
};
