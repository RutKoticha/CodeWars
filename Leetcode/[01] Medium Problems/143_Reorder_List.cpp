/**
 * Author: Rut Koticha
 * Date: 2025-10-06 21:41
 * File: 143_Reorder_List.cpp
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
  void reorderList(ListNode *head) {
    std::vector<ListNode *> pointers;

    ListNode *iter = head;
    while (iter) {
      pointers.push_back(iter);
      iter = iter->next;
    }

    if (pointers.size() <= 2) {
      return;
    }

    int left = 0;
    int right = pointers.size() - 1;

    while (left < right) {
      pointers[right]->next = pointers[left]->next;
      pointers[left]->next = pointers[right];

      left++;
      right--;
    }

    pointers[left]->next = nullptr;
  }
};
