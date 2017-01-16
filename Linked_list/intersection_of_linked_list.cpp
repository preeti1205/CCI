/* CTCI linked list problem 7 */

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
  ListNode* intersection(ListNode* head1, ListNode* head2) {
    ListNode* ptr1 = head1;
    ListNode* ptr2 = head2;

    while(ptr1 || ptr2) {
      if (ptr1 == ptr2) return ptr1;
      ptr1 = ptr1->next;
      ptr2 = ptr2->next;
      if (!ptr1 && !ptr2) return ptr1;
      if(ptr1 == NULL) ptr1 = head2;
      if(ptr2 == NULL) ptr2 = head1;
    }
    return ptr1;
  }
};

int main() {
  Solution sol;
  int n,m, k;
  int counter = 0;
  ListNode* intersect = NULL;
  ListNode head1(0);
  ListNode head2(0);
  ListNode* curr = &head1;
  ListNode* curr2 = &head2;
  cout << "Enter the size of the linked list 1 and 2 (larger first): ";
  cin >> m >> n;
  cout << "enter the intersection index wrt linked list 1 (1 indexed) :";
  cin >> k;
  cout << " Enter the linked list 1 elements: ";
  int num;
  for(int i = 0; i < m; i++) {
    cin>>num;
    curr->next = new ListNode(num);
    curr = curr->next;
    counter++;
    if(counter == k) intersect = curr;
  }
  cout << "Enter the " << n - (m - k + 1) << " uncommon elements ";
  for(int i = 0; i < (n - (m - k + 1)); i++) {
    cin>>num;
    curr2->next = new ListNode(num);
    curr2 = curr2->next;
  }
  curr2->next = intersect;
  ListNode* result = sol.intersection(head1.next, head2.next) ;
  if (result) cout << result->val << endl;
  else cout << "no intersection" << endl;
  return 0;
}
