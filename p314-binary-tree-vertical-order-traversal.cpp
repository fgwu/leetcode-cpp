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
	/*1035*/
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> rv;
		if(!root) return rv;

		queue<pair<int, TreeNode*>> q; // col, TreeNode
		map<int, vector<int>> m; // col -> vec
		q.emplace(0, root);
		while(!q.empty()) {
			int col = q.front().first;
			TreeNode* p = q.front().second;
			q.pop();
			m[col].push_back(p->val);
			if (p->left)
				q.emplace(col - 1, p->left);
			if (p->right)
				q.emplace(col + 1, p->right);
		}
		for (auto e: m)
			rv.push_back(e.second);

		return rv;
	}


	//     struct Elem {
	//         int col;
	//         int row;
	//         long path;
	//         TreeNode* node;
	//         Elem(int c, int r, int p, TreeNode* n): col(c), row(r), path(p), node(n){}
	//     };

	//     /*20171124 0943*/
	//     /*         1016*/
	//     /*AC       1021*/
	//     vector<vector<int>> verticalOrder(TreeNode* root) {
	//         vector<Elem> v;
	//         queue<Elem> q;
	//         vector<vector<int>> rv;
	//         if (!root) return rv;
	//         q.emplace(0, 0, 0, root);
	//         while(!q.empty()) {
	//             int c = q.front().col;
	//             int r = q.front().row;
	//             long p = q.front().path;
	//             TreeNode* n = q.front().node;
	//             v.push_back(q.front());
	//             q.pop();
	//             if (n->left)
	//                 q.emplace(c - 1, r + 1, p << 1, n->left);
	//             if (n->right)
	//                 q.emplace(c + 1, r + 1, (p << 1) | 1, n->right);
	//         }

	//         sort(v.begin(), v.end(), [](const Elem& a, const Elem& b){
	//             if (a.col != b.col) return a.col < b.col;
	//             if (a.row != b.row) return a.row < b.row;
	//             return a.path < b.path;
	//         });

	//         vector<int> tmp;
	//         for (int i = 0; i < v.size(); i++) {
	//             if (!i || v[i].col == v[i - 1].col) {
	//                 tmp.push_back(v[i].node->val);
	//                 continue;
	//             }

	//             rv.push_back(tmp);
	//             tmp.resize(0);
	//             tmp.push_back(v[i].node->val);
	//         }

	//         rv.push_back(tmp);

	//         return rv;
	//     }
};
