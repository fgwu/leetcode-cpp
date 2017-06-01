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
	/*iterator*/
	/*20170531 1409*/
	/*AC       1415*/
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (!root) return res;
		stack<TreeNode*> ns;
		stack<string> ss;
		ns.push(root);
		ss.push(to_string(root->val));
		while (!ss.empty()) {
			TreeNode* tmpn = ns.top();
			string tmps = ss.top();
			ns.pop();
			ss.pop();
			if (!tmpn->left && !tmpn->right) {res.push_back(tmps); continue;}
			if (tmpn->left) {ns.push(tmpn->left); ss.push(tmps + "->" + to_string(tmpn->left->val));}
			if (tmpn->right) {ns.push(tmpn->right); ss.push(tmps + "->" + to_string(tmpn->right->val));}
		}
		return res;
	}




	/*20170531 1354*/
	/*AC       1408*/
	// void dfs(TreeNode* root, vector<string>& res, string path) {
	//     if (!root->left && !root->right) { res.push_back(path); return; }
	//     if (root->left) dfs(root->left, res, path + "->" + to_string(root->left->val));
	//     if (root->right) dfs(root->right, res, path + "->" + to_string(root->right->val));
	// }

	// vector<string> binaryTreePaths(TreeNode* root) {
	//     vector<string> res;
	//     if (!root) return res;
	//     dfs(root, res, to_string(root->val));
	//     return res;
	// }
};
