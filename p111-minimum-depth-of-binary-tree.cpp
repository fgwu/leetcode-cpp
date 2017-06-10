/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	/*20170609 1204*/
	/*AC       1209*/
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		if (!root->left && !root->right) return 1;
		if (root->left && root->right) return 1 + min(minDepth(root->left), minDepth(root->right));
		if (root->left) return 1 + minDepth(root->left);
		return 1 + minDepth(root->right);
	}
};
