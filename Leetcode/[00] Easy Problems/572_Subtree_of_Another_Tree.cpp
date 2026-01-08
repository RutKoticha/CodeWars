/**
 * Author: Rut Koticha
 * Date: 2025-10-08 18:43
 * File: 572_Subtree_of_Another_Tree.cpp
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
private:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p || !q) {
      return (!p && !q);
    }

    if (p->val != q->val) {
      return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }

public:
  bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    if (isSameTree(root, subRoot)) {
      return true;
    }

    return (root->left && isSubtree(root->left, subRoot)) ||
           (root->right && isSubtree(root->right, subRoot));
  }
};
