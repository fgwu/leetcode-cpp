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
	/*20170522 1446*/
	/*         1454 Bug: levelq template is int instead of TreeNode* */
	/*AC       1458 value<int> is not node <TreeNode*> */
	int findBottomLeftValue(TreeNode* root) {
		int rv = 0, level, last_level = 0;
		queue<TreeNode*> q;
		queue<int> levelq;
		TreeNode *n;

		if (!root) return rv;
		q.push(root);
		levelq.push(1);
		while (!q.empty()) {
			n = q.front();
			level = levelq.front();
			if (level > last_level)
				rv = n->val;
			last_level = level;
			if (n->left) { q.push(n->left); levelq.push(level + 1);}
			if (n->right) { q.push(n->right); levelq.push(level + 1);}
			q.pop();
			levelq.pop();
		}
		return rv;
	}
};
