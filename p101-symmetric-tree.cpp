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
	/*seen solution. no need to ensure the children not to be null.*/
	/*AC 20170530 0026*/
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode*> q1, q2;
		q1.push(root);
		q2.push(root);
		for (; !q1.empty() && !q2.empty(); q1.pop(), q2.pop()){
			TreeNode*n1 = q1.front(), *n2 = q2.front();
			if (!n1 && !n2) continue;
			if (!n1 || !n2) return false;
			if (n1->val != n2->val) return false;
			q1.push(n1->left);
			q1.push(n1->right);
			q2.push(n2->right);
			q2.push(n2->left);
		}
		return true;
	}



	/*20170530 0000 Iterative*/
	/*AC       0015*/
	// bool isSymmetric(TreeNode* root) {
	//     if (!root) return true;
	//     queue<TreeNode*> q1, q2;
	//     q1.push(root);
	//     q2.push(root);
	//     for (; !q1.empty() && !q2.empty(); q1.pop(), q2.pop()){
	//         TreeNode*n1 = q1.front(), *n2 = q2.front();
	//         // cout << n1->val << " " << n2->val << "\n";
	//         if (n1->val != n2->val) return false;
	//         if (n1->left && n2->right) {q1.push(n1->left); q2.push(n2->right);}
	//         else if (n1->left || n2->right) return false;
	//         if (n1->right && n2->left) {q1.push(n1->right); q2.push(n2->left);}
	//         else if (n1->right || n2->left) return false;
	//     }

	//     if (!q1.empty() || !q2.empty()) return false;
	//     return true;
	// }

	/*20170529 2356 REC*/
	/*AC       2359*/
	// bool isMirror(TreeNode* t1, TreeNode* t2) {
	//     if (!t1 && !t2) return true;
	//     if (!t1 || !t2) return false;
	//     if (t1->val != t2->val) return false;
	//     return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
	// }

	// bool isSymmetric(TreeNode* root) {
	//     return isMirror(root, root);
	// }
};
