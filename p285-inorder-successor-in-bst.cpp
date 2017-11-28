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
	/*20171122 0651*/
	/*AC       0705*/
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
		if (!root || !p) return nullptr;

		TreeNode *curr, *cand;
		if(p->right) {
			curr = p->right;
			while(curr->left) curr = curr->left;
			return curr;
		}

		curr = root;
		while(curr != p) {
			if (curr->val < p->val)
				curr = curr->right;
			else {
				cand = curr;
				curr = curr->left;
			}
		}

		return cand;
	}
};
