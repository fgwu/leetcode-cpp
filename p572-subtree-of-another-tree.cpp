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
	/*AC 20170524 0028*/
	bool sameTree(TreeNode* s, TreeNode* t) {
		if (!s && !t) return true;
		if (!s || !t) return false;
		if (s->val != t->val) return false;
		if (!sameTree(s->left, t->left)) return false;
		if (!sameTree(s->right, t->right)) return false;
		return true;
	}

	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (!t) return true;
		if (!s) return false;
		if (t->val == s->val && sameTree(s, t)) return true;
		if (isSubtree(s->left, t)) return true;
		if (isSubtree(s->right, t)) return true;
		return false;
	}
};
