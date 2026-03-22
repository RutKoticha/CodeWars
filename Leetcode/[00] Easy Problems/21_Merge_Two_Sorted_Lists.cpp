/**
 * Author: Rut Koticha
 * Date: 2025-08-30 23:32
 */

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
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *pointer1 = list1;
    ListNode *pointer2 = list2;
    ListNode *merged = new ListNode();

    ListNode *merging = merged;

    // Merge using both the lists
    while (pointer1 && pointer2) {
      if (pointer1->val > pointer2->val) {
        merging->next = pointer2;
        pointer2 = pointer2->next;
      } else {
        merging->next = pointer1;
        pointer1 = pointer1->next;
      }

      merging = merging->next;
    }

    // Add the remaining part of the lists
    if (pointer1) {
      merging->next = pointer1;
    } else {
      merging->next = pointer2;
    }

    // Ideally we should remove the first node
    // But I don't know how it is initialized
    return merged->next;
  }
};