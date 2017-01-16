/* CTCI linked list problem 5 */

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
  bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;

    while(fast && fast->next) {
      fast = fast->next->next;
      ListNode* temp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = temp;
      //fast = fast->next->next;   -----> not here - gives segmentation fault
    }

    if(fast) slow = slow->next;

    while(slow != NULL) {
      if(prev->val != slow->val) return false;
      slow = slow->next;
      prev = prev->next;
    }

    return true;
  }
};

int main() {
  Solution sol;
  int n;
  ListNode head(0);
  ListNode* curr = &head;
  cout << "Enter the size of the linked list : ";
  cin >> n;
  cout << " Enter the linked list elements: ";
  int num;
  for(int i = 0; i < n; i++) {
    cin>>num;
    curr->next = new ListNode(num);
    curr = curr->next;
  }
  cout << sol.isPalindrome(head.next) << endl;
  return 0;
}
