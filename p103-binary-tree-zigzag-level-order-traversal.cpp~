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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> res;
		if (!root) return res;
		q.push(root);

		for (int level = 0; !q.empty(); level++) {
			int s = q.size();
			vector<int> tmp(s);
			for (int i = 0; i < s; i++) {
				int idx = level%2? s - 1 - i: i;
				TreeNode* n = q.front();
				q.pop();
				tmp[idx] = n->val;
				if (n->left) q.push(n->left);
				if (n->right) q.push(n->right);
			}
			res.push_back(tmp);
		}

		return res;
	}

	/* single queue, no reverse */
	/* 1643   */
	/*2138*/
	//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	//         queue<TreeNode*> q;
	//         vector<vector<int>> res;
	//         if (!root) return res;
	//         q.push(root);

	//         int size = 1;
	//         int level = 0;
	//         int idx = 0;
	//         res.push_back(vector<int>(1));
	//         while(!q.empty()) {
	//             TreeNode* n = q.front();
	//             q.pop();

	//             if (level%2)  // odd, need reverse
	//                 res[level][size - 1 - idx] = n->val;
	//             else // even no need to reverse
	//                 res[level][idx] = n->val;

	//             if (n->left) q.push(n->left);
	//             if (n->right) q.push(n->right);

	//             if (++idx == size) { // the boundary of level
	//                 idx = 0;
	//                 size = q.size();
	//                 if (!size) break;
	//                 res.push_back(vector<int>(size));
	//                 level++;
	//             }
	//         }

	//         return res;
	//     }


	/*DFS   1634*/
	/*AC    1642*/
	//     void dfs(TreeNode* root, vector<vector<int>>& res, int level) {
	//         if (res.size() <= level)
	//             res.push_back(vector<int>(1, root->val));
	//         else
	//             res[level].push_back(root->val);
	//         if (root->left) dfs(root->left, res, level + 1);
	//         if (root->right) dfs(root->right, res, level + 1);
	//     }

	//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	//         vector<vector<int>> res;
	//         if (!root) return res;
	//         dfs(root, res, 0);

	//         for (int i = 0; i < res.size(); i++){
	//             if (i%2 == 0) continue;
	//             reverse(res[i].begin(), res[i].end());
	//         }
	//         return res;
	//     }


	/*20170802 1621*/
	/*AC       1630*/
	//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	//         queue<TreeNode*> nq;
	//         queue<int> lq;
	//         vector<vector<int>> res;
	//         if (!root) return res;

	//         nq.push(root);
	//         lq.push(0);

	//         vector<int> tmp;

	//         while(!nq.empty()) {
	//             TreeNode* n = nq.front();
	//             nq.pop();
	//             int l = lq.front();
	//             lq.pop();

	//             if (n->left) {
	//                 nq.push(n->left);
	//                 lq.push(l + 1);
	//             }

	//             if (n->right) {
	//                 nq.push(n->right);
	//                 lq.push(l + 1);
	//             }

	//             tmp.push_back(n->val);

	//             if (lq.empty() || l != lq.front()) {
	//                 if (l % 2) reverse(tmp.begin(), tmp.end());
	//                 res.push_back(tmp);
	//                 tmp.clear();
	//             }
	//         }

	//         return res;
	//     }
};
