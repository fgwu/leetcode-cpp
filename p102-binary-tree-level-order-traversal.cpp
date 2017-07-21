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
	/*20170920 1609*/
	/*AC       1618*/
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> nq;
		queue<int> lq;
		vector<vector<int>> res;
		if (!root) return res;

		nq.push(root);
		lq.push(0);
		vector<int> tmplist;
		while(!nq.empty()) {
			TreeNode* n = nq.front();
			nq.pop();
			int l = lq.front();
			lq.pop();

			if (n->left) {
				nq.push(n->left);
				lq.push(l + 1);
			}
			if (n->right) {
				nq.push(n->right);
				lq.push(l + 1);
			}

			tmplist.push_back(n->val);

			if (lq.empty() || lq.front() != l) {
				res.push_back(tmplist);
				tmplist.clear();
			}
		}
		return res;
	}
};
