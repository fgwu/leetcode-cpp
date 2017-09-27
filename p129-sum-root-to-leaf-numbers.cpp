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
	/*20170926 2034*/
	/*AC       2043*/
	void dfs(TreeNode* root, int partial, int& sum) {
		if (!root) return;
		partial = partial * 10 + root->val;
		if (!root->left && !root->right) {
			sum += partial;
			return;
		}

		dfs(root->left, partial, sum);
		dfs(root->right, partial, sum);
	}

	int sumNumbers(TreeNode* root) {
		int sum = 0, partial = 0;
		dfs(root, partial, sum);
		return sum;
	}
};
