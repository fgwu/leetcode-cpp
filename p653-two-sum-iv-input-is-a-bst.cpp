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
	/*20171122  0738*/
	/*AC        1019*/
	bool check(TreeNode* root, int v) {
		if (!root) return false;
		if (root->val == v) return true;
		if (root->val < v)
			return check(root->right, v);
		else
			return check(root->left, v);
	}


	bool findTarget(TreeNode* root, int k) {
		if (!root) return false;
		stack<TreeNode*> s;
		s.push(root);
		TreeNode *curr;
		while(!s.empty()) {
			curr = s.top();
			if (k != curr->val * 2 && check(root, k - curr->val)) return true;
			s.pop();
			if (curr->left) s.push(curr->left);
			if (curr->right) s.push(curr->right);
		}

		return false;
	}
};
