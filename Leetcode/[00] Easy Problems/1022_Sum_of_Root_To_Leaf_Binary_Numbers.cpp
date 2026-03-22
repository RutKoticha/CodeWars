/**
 * @file 1022_Sum_of_Root_To_Leaf_Binary_Numbers.cpp
 * @author Rut Koticha
 * @date 2026-02-24
 */

#ifdef LOCAL_RUN
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
	int sumRootToLeaf(TreeNode* root, int value = 0)
	{
		value = (value << 1) | root->val;

		if (!root->left && !root->right)
			return value;

		int sum = 0;

		if (root->left)
			sum += sumRootToLeaf(root->left, value);

		if (root->right)
			sum += sumRootToLeaf(root->right, value);

		return sum;
	}
};
