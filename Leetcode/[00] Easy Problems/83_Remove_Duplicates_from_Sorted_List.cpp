#include <bits/stdc++.h>

/**
 * Author:	Rut Koticha
 * Created at:	2025-03-01 09:12:38 (Saturday)
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head);
};

ListNode* Solution::deleteDuplicates(ListNode* head) {
    auto itr = head;

    while(itr) {
        auto link = itr;
        while(itr->next && itr->next->val == link->val) {
            itr = itr->next;
        }
        itr = itr->next;
    }

    return head;
}
