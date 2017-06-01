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
	/*20170531 1417*/
	/*AC       1422*/
	bool isBalancedRec(TreeNode* root, int &height) {
		if (!root) {height = 0; return true;}
		int h1 = 0, h2 = 0;
		if (!isBalancedRec(root->left, h1) || !isBalancedRec(root->right, h2)){ return false;}
		if (abs(h1 - h2) > 1) return false;
		height = max(h1, h2) + 1;
		return true;
	}

	bool isBalanced(TreeNode* root) {
		int dummyheight = 0;
		return isBalancedRec(root, dummyheight);
	}
};
