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
	/*20170521 0108*/
	/*         0114*/
	/*AC       0115 bug free*/
	void inorder(TreeNode* n, int & last_val) {
		if (!n) return;
		inorder(n->right, last_val);
		n->val += last_val;
		last_val = n->val;
		inorder(n->left, last_val);
	}

	TreeNode* convertBST(TreeNode* root) {
		int last_val = 0;
		inorder(root, last_val);
		return root;
	}
};
