/**
 * Author: Rut Koticha
 * Date: 2025-08-30 23:49
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
  bool hasCycle(ListNode *head) {
    ListNode *rabbit = head; // Just fun name for fast pointer
    ListNode *turtle = head; // Just fun name for slow pointer

    while (rabbit && turtle) {
      rabbit = rabbit->next;
      if (rabbit) {
        rabbit = rabbit->next;
      } else {
        return false;
      }

      turtle = turtle->next;

      if (rabbit == turtle) {
        return true;
      }
    }

    return false;
  }
};
