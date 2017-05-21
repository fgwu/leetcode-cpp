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
	/*20170521 0031*/
	/*         0046*/
	/*AC       0048 After the while loop, check whethe the last value is collocted.*/
	vector<int> largestValues(TreeNode* root) {
		queue<TreeNode*> tq;
		queue<int> lq;
		vector<int> rv;
		int curr_level = 0, max_val = INT_MIN;
		if (!root) return rv;
		tq.push(root);
		lq.push(1);
		while(!tq.empty()) {
			TreeNode *n = tq.front();
			tq.pop();
			int l = lq.front();
			lq.pop();

			if (l > curr_level) {
				if (curr_level)
					rv.push_back(max_val);
				curr_level = l;
				max_val = INT_MIN;
			}

			max_val = max(max_val, n->val);

			if (n->left) {
				tq.push(n->left);
				lq.push(l + 1);
			}

			if (n->right) {
				tq.push(n->right);
				lq.push(l + 1);
			}
		}

		rv.push_back(max_val);

		return rv;
	}
};
