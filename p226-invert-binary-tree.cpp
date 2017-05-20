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
	/*20170518 15:23*/
	/*AC       15:30*/
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) return root;
		TreeNode* tmpright = invertTree(root->left);
		TreeNode* tmpleft = invertTree(root->right);
		root->left = tmpleft;
		root->right = tmpright;
		return root;
	}
};
