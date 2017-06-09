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
	/*20170608 1353*/
	/*AC       1502*/
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (!root->left &&  !root->right && root->val == sum) return true;
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
	}
};
