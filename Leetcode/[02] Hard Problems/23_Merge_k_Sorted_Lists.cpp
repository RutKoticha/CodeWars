/**
 * Author: Rut Koticha
 * Date: 2025-10-06 22:38
 * File: 23_Merge_k_Sorted_Lists.cpp
 */

#include <vector>

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
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    // Edge case 1 : No lists
    if (lists.empty()) {
      return nullptr;
    }

    ListNode *dummy = new ListNode(-1, nullptr);
    ListNode *iter = dummy;

    while (true) {
      ListNode *min = nullptr;
      ListNode **min_ptr = nullptr;

      // Find Minimum
      for (ListNode *&head : lists) {
        if (!head) {
          continue;
        }

        if (!min) {
          min = head;
          min_ptr = &head;
        }

        if (min->val > head->val) {
          min = head;
          min_ptr = &head;
        }
      }

      if (!min) {
        break;
      }

      // Append to the answer list
      iter->next = min;
      iter = iter->next;

      *min_ptr = (*min_ptr)->next;
    }

    ListNode *head = dummy->next;
    delete dummy;
    return head;
  }
};
