/**
 * Author: Rut Koticha
 * Date: 2025-10-07 22:13
 * File: 226_Invert_Binary_Tree.cpp
 */

#include <algorithm>

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
  TreeNode *invertTree(TreeNode *root) {
    if (!root) {
      return nullptr;
    }

    std::swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
  }
};
