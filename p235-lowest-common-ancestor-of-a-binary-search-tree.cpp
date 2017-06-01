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
	/*AC 20170529 0118 */
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || !p || !q) return nullptr;
		if (p->val > q->val) swap(q, p);
		if (root->val >= p->val && root->val <= q->val) return root;
		if (root->val > p->val) return lowestCommonAncestor(root->left, p, q);
		return lowestCommonAncestor(root->right, p, q);
	}
};
