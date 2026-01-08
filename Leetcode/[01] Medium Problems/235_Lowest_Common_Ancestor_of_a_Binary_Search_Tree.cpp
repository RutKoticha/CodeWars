/**
 * Author: Rut Koticha
 * Date: 2025-10-13 11:05
 * File: 235_Lowest_Common_Ancestor_of_a_Binary_Search_Tree.cpp
 */

#include <iostream>

#ifdef LOCAL_RUN
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#endif

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (p->val < root->val && q->val < root->val) {
      return lowestCommonAncestor(root->left, p, q);
    }

    if (p->val > root->val && q->val > root->val) {
      return lowestCommonAncestor(root->right, p, q);
    }

    return root;
  }
};
