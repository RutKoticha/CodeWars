/**
 * Author: Rut Koticha
 * Date: 2025-10-14 10:20
 * File: 105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp
 */

#include <algorithm>
#include <vector>

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
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (!preorder.size() || !inorder.size()) {
      return nullptr;
    }

    TreeNode *root = new TreeNode(preorder[0]);
    preorder.erase(preorder.begin());

    auto mid = std::find(inorder.begin(), inorder.end(), root->val);

    std::vector<int> left = std::vector<int>(inorder.begin(), mid);
    std::vector<int> right = std::vector<int>(mid + 1, inorder.end());

    if (left.size() > 0) {
      TreeNode *leftSubtree = buildTree(preorder, left);
      root->left = leftSubtree;
    }

    if (right.size() > 0) {
      TreeNode *rightSubtree = buildTree(preorder, right);
      root->right = rightSubtree;
    }

    return root;
  }
};
