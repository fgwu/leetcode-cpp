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
	/*Morris 20170919 2:28*/
	/*AC              3:53*/
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode* curr = root;
		while (curr) {
			if (curr->left) {
				TreeNode* tmp = curr->left;
				while (tmp->right) tmp = tmp->right;
				tmp->right = curr;
				curr = curr->left;
				/*IMPORTANT!!!! to avoid infinite loop */
				tmp->right->left = nullptr;
			} else {
				res.push_back(curr->val);
				curr = curr->right;
			}
		}
		return res;
	}

	/*itr vertion test*/
	/*20170919   1:44*/
	/*AC 1:48*/
	//         vector<int> inorderTraversal(TreeNode* root) {
	//             stack<TreeNode*> s;
	//             vector<int> res;
	//             s.push(root);

	//             while(!s.empty()) {
	//                 TreeNode* p = s.top();
	//                 s.pop();
	//                 if (!p) continue;
	//                 if (s.empty() || s.top() != p->right) {
	//                     s.push(p->right);
	//                     s.push(p);
	//                     s.push(p->left);
	//                     continue;
	//                 }
	//                 res.push_back(p->val);
	//             }
	//             return res;
	//         }


	/*itr version*/
	/*20170524 1155*/
	/*AC       1216*/
	// vector<int> inorderTraversal(TreeNode* root) {
	//     vector<int> res;
	//     stack<TreeNode*> s;
	//     s.push(root);
	//     while (!s.empty()){
	//         TreeNode* tmp = s.top();
	//         s.pop();
	//         if (!tmp) continue;
	//         if (!s.empty() && tmp->right == s.top()) {
	//             res.push_back(tmp->val);
	//             continue;
	//         }
	//         s.push(tmp->right);
	//         s.push(tmp);
	//         s.push(tmp->left);
	//     }
	//     return res;
	// }


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
