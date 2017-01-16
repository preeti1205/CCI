/* CTCI linked list problem 4 */

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
  ListNode* partition(ListNode* head, int x) {
    ListNode* newhead = head;
    ListNode* smallhead = NULL;
    ListNode* smalltail = NULL;
    ListNode* largehead = NULL;
    ListNode* largetail = NULL;

    while(head) {
      if (head->val < x) {
        if(smallhead == NULL) {
          smallhead = head;
          smalltail = head;
        }
        else {
          smalltail->next = head;
          smalltail = smalltail->next;
        }
      }
      else {
        if(largehead == NULL) {
          largehead = head;
          largetail = head;
        }
        else {
          largetail->next = head;
          largetail = largetail->next;
        }
      }
      head = head->next;
    }
    if (smallhead == NULL) return largehead;
    smalltail->next = largehead;

    return smallhead;
  }
};

int main() {
  int n, k;
  ListNode head(0);
  ListNode* curr = &head;
  Solution sol;
  cout << "Enter the size of the linked list : ";
  cin >> n;
  cout << " Enter the linked list elements: ";
  int num;
  for(int i = 0; i < n; i++) {
    cin>>num;
    curr->next = new ListNode(num);
    curr = curr->next;
  }
  cout << "Enter k: ";
  cin >> k;
  ListNode* result = sol.partition(head.next, k);
  cout << result->val << endl;
  /*
  while(result) {
    cout << result->val << "-> ";
    result = result->next;
  }
  */
  return 0;
}
