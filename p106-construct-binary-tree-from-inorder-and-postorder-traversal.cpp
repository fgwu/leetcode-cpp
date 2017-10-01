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
	/*20170927 2338*/
	/*AC 0012*/
	TreeNode* helper(vector<int>& inorder, int in_left, int in_right,
			 vector<int>& postorder, int post_left, int post_right) {
		if (in_right - in_left != post_right - post_left) return nullptr;
		if (in_left >= in_right) return nullptr;
		int val = postorder[post_right - 1];
		TreeNode * root = new TreeNode(val);
		int idx = find(inorder.begin(), inorder.end(), val) - inorder.begin();
		if (idx == inorder.size()) return nullptr;
		root->left = helper(inorder, in_left, idx,
				    postorder, post_left, post_left + (idx - in_left));
		root->right = helper(inorder, idx + 1, in_right,
				     postorder, post_right - (in_right - idx - 1) - 1, post_right - 1);
		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() != postorder.size()) return nullptr;
		return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}
};
