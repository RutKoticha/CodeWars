/**
 * Author: Rut Koticha
 * Date: 2025-10-07 22:24
 * File: 100_Same_Tree.cpp
 */

#ifdef LOCAL_RUN
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p || !q) {
      return (!p && !q);
    }

    if (p->val != q->val) {
      return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
