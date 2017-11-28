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
	/*20171122  1149*/
	/*AC        1154*/
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> rv;
		if (!root) return rv;

		vector<TreeNode*> level;
		level.push_back(root);

		while(level.size()) {
			vector<TreeNode*> next;
			double sum = 0;
			for (auto p: level){
				sum += p->val;
				if (p->left) next.push_back(p->left);
				if (p->right) next.push_back(p->right);
			}
			rv.push_back(sum / level.size());
			swap(level, next);
		}

		return rv;
	}
};
