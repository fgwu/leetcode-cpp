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

	/*DFS recursive */
	/*AC 20170527 2347*/
	void DFS(TreeNode* root, int level, vector<vector<int>> & res) {
		if (!root) return;
		if (res.size() == level) res.insert(res.begin(), vector<int>());
		res[res.size() - 1 - level].push_back(root->val);
		DFS(root->left, level + 1, res);
		DFS(root->right, level + 1, res);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		DFS(root, 0, res);
		return res;
	}




	/*seen solution, try DFS */
	/*AC 20170527 2342*/
	// vector<vector<int>> levelOrderBottom(TreeNode* root) {
	//     vector<vector<int>> res;
	//     if (!root) return res;
	//     stack<TreeNode*> ns;
	//     stack<int> ls;
	//     ns.push(root);
	//     ls.push(0);
	//     while (!ns.empty()) {
	//         TreeNode* n = ns.top();
	//         ns.pop();
	//         int l = ls.top();
	//         ls.pop();
	//         if (res.size() == l) res.insert(res.begin(), vector<int>());
	//         res[res.size() - l - 1].push_back(n->val);
	//         if (n->right) {ns.push(n->right); ls.push(l + 1);}
	//         if (n->left) {ns.push(n->left); ls.push(l + 1);}
	//     }
	//     return res;
	// }


	/*AC 20170527 2330 Note: after the loop, check the remaining data to reflect in to res*/
	// vector<vector<int>> levelOrderBottom(TreeNode* root) {
	//     queue<TreeNode*> nq;
	//     queue<int> lq;
	//     vector<vector<int>> res;
	//     if (!root) return res;
	//     nq.push(root);
	//     lq.push(0);
	//     int prev_level = 0;
	//     vector<int> tmp;
	//     for (; !nq.empty(); nq.pop(), lq.pop()) {
	//         TreeNode* n = nq.front();
	//         int l = lq.front();
	//         if (n->left) {nq.puåsh(n->left); lq.push(l + 1);}
	//         if (n->right) {nq.push(n->right); lq.push(l + 1);}
	//         if (l == prev_level) { tmp.push_back(n->val); continue; }
	//         prev_level = l;
	//         res.insert(res.begin(), tmp);
	//         tmp.clear();
	//         tmp.push_back(n->val);

	//     }
	//     res.insert(res.begin(), tmp);
	//     return res;
	// }
};
