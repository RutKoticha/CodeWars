/**
 * Author: Rut Koticha
 * Date: 2025-08-30 23:17
 */

#include <iostream>

// #ifdef LOCAL_RUN
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// #endif

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    // Setup the required pointers
    ListNode *prev = nullptr;
    ListNode *curr = head;

    // Loop until the current pointer becomes null
    while (curr != nullptr) {
      ListNode *temp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = temp;
    }

    return prev;
  }
};
