/**
 * Author: Rut Koticha
 * Date: 2025-10-13 11:41
 * File: 230_Kth_Smallest_Element_in_a_BST.cpp
 */

#include <vector>

const int INVALID = -1;

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
  int find(TreeNode *root, int &k) {
    if (root->left) {
      int value = find(root->left, k);
      if (value != INVALID) {
        return value;
      }
    }

    k--;
    if (!k) {
      return root->val;
    }

    if (root->right) {
      int value = find(root->right, k);
      if (value != INVALID) {
        return value;
      }
    }

    return INVALID;
  }

public:
  int kthSmallest(TreeNode *root, int k) { return find(root, k); }
};
