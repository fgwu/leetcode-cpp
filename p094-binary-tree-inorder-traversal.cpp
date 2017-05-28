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
	/*itr version*/
	/*20170524 1155*/
	/*AC       1216*/
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty()){
			TreeNode* tmp = s.top();
			s.pop();
			if (!tmp) continue;
			if (!s.empty() && tmp->right == s.top()) {
				res.push_back(tmp->val);
				continue;
			}
			s.push(tmp->right);
			s.push(tmp);
			s.push(tmp->left);
		}
		return res;
	}


	/*20170524 1151*/
	/*AC       1154*/
	// private:
	//     void inOrderRec(TreeNode * root, vector<int> & res) {
	//         if (!root) return;
	//         if (root->left) inOrderRec(root->left, res);
	//         res.push_back(root->val);
	//         if (root->right) inOrderRec(root->right, res);
	//     }
	// public:
	//     vector<int> inorderTraversal(TreeNode* root) {
	//         vector<int> res;
	//         inOrderRec(root, res);
	//         return res;
	//     }
};
