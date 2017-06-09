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
	int max_cnt = INT_MIN;
	int cnt = 0, curr;
public:
	void inorder(TreeNode* root, vector<int> & res) {
		if (!root) return;
		// cout << "enter: root->val" << root->val << " " << res.size() << "\n";
		inorder(root->left, res);
		if (!cnt) {
			curr = root->val;
			cnt++;
			res.push_back(curr);
		} else {
			if (root->val == curr) cnt++;
			else {
				if (cnt > max_cnt) { res.clear(); res.push_back(curr); max_cnt = cnt; }
				else if (cnt == max_cnt) res.push_back(curr);
				curr = root->val;
				cnt = 1;
			}
		}

		inorder(root->right, res);
		// cout << "exit:  root->val" << root->val << " " << res.size() << "\n";

	}

	vector<int> findMode(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		if (!cnt) return res;
		// cout << cnt << " " << max_cnt << " " << curr << "\n";
		if (cnt > max_cnt) { res.clear(); res.push_back(curr);}
		else if (cnt == max_cnt) res.push_back(curr);
		return res;
	}
};
