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
	/*morris 20170919 0304*/
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode* curr = root;
		while (curr) {
			res.push_back(curr->val);
			if (curr->left && curr->right) {
				TreeNode* end = curr->left;
				while(end->right) end = end->right;
				end->right = curr->right;
				/*IMPORTANT!! housekeeping*/
				curr->right = nullptr;
				curr = curr->left;
				continue;
			}

			if (curr->left) {
				curr = curr->left;
				continue;
			}

			if (curr->right) {
				curr = curr->right;
				continue;
			}

			break;
		}
		return res;
	}
};
