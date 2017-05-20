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
	/*20170519 23:03*/
	/*         23:15*/
	/*AC       23:17 bug free*/
	int sumOfLeftLeaves(TreeNode* root) {
		int rv = 0;
		traverse(root, false, rv);
		return rv;
	}

	void traverse(TreeNode* n, bool isleftchild, int &rv) {
		if (!n) return;

		if (!n->left && !n->right && isleftchild){
			rv += n->val;
			return;
		}

		traverse(n->left, true, rv);
		traverse(n->right, false, rv);
	}
};
