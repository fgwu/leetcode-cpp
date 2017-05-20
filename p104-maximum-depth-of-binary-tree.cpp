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
	/*20170518 14:30*/
	/*         14:32*/
	/*AC       14:33*/
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};
