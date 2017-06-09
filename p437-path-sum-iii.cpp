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
	/*sln copied..*/
	int help(TreeNode* root, int sum, unordered_map<int, int>& store, int pre) {
		if (!root) return 0;
		cout << root->val << "\n";
		for(const auto & p:store)
			if (p.second) cout << " " << p.first << " " << p.second << "\n";
		root->val += pre;
		cout << " root->val " << root->val << " sum " << sum << " root->val - sum " << root->val - sum << "\n";
		int res = (root->val == sum) + (store.count(root->val - sum) ? store[root->val - sum] : 0);
		store[root->val]++;
		res += help(root->left, sum, store, root->val) + help(root->right, sum, store, root->val);
		store[root->val]--;
		return res;
	}

	int pathSum(TreeNode* root, int sum) {
		unordered_map<int, int> store;
		return help(root, sum, store, 0);
	}

	/*20170601 1746*/
	/*AC       1755*/
	// void dfs(TreeNode* root, vector<int> path, int sum, int &res) {
	//     if (!root) return;
	//     path.push_back(0);
	//     for (auto & v: path) {
	//         v += root->val;
	//         if (v == sum) res++;
	//     }
	//     dfs(root->left, path, sum, res);
	//     dfs(root->right, path, sum, res);
	// }
	// int pathSum(TreeNode* root, int sum) {
	//     int res = 0;
	//     vector<int> path;
	//     dfs(root, path, sum, res);
	//     return res;
	// }
};
