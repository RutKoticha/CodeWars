/**
 * Author: Rut Koticha
 * Date: 2025-10-06 22:02
 * File: 19_Remove_Nth_Node_From_End_of_List.cpp
 */

#ifdef LOCAL_RUN
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(-1, head);

    ListNode *left = dummy;
    ListNode *right = dummy;

    // Space the two pointers n nodes apart
    int difference = n;
    while (difference--) {
      // Edge case 1 : n > length
      if (!right || !right->next) {
        return head;
      }

      right = right->next;
    }

    // Edge case 2 : n == length
    if (!right || !right->next) {
      head = head->next;
      delete left;
      return head;
    }

    // Move both pointers until end
    while (right && right->next) {
      left = left->next;
      right = right->next;
    }

    // Remove the element
    ListNode *temp = left->next;
    left->next = temp->next;
    delete temp;
    temp = nullptr;

    return head;
  }
};
