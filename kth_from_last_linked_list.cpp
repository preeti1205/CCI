/* CLRS linked list prob 2 */
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  ListNode* kth_element(ListNode* head, int k) {
    ListNode* slow = head;
    ListNode* fast = head;
    int counter = 0;
    while(counter <= k){
      fast = fast->next;
      counter++;
    }
    while(fast){
      fast = fast->next;
      slow = slow->next;
    }

    return slow;
  }
};

int main() {
  int n, k;
  Solution sol;
  ListNode prestart(0);
  ListNode* head = &prestart;
  ListNode* curr = &prestart;
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
  ListNode* result = sol.kth_element(head->next, k);
  cout << result->val << endl;
  return 0;
}
