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
	/*20170524 0010*/
	void helper (TreeNode* root,
		     int &h, int &d){ //ret: height and diameter
		int hl, hr, dl, dr;
		if (!root) {
			h = d = 0;
			return;
		}
		helper(root->left, hl, dl);
		helper(root->right, hr, dr);
		d = max(hl + hr, max(dl, dr));
		h = max(hl, hr) + 1;
		// cout << root->val << ": ";
		// cout << "d=" << d << " h=" << h;
		// cout << " dl=" << dl << " hl=" << hl;
		// cout << " dr=" << dr << " hr=" << hr << "\n";
	}

	int diameterOfBinaryTree(TreeNode* root) {
		int h = 0, d = 0;
		helper(root, h, d);
		return d;
	}
};
