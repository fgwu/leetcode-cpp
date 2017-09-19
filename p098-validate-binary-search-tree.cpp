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
	/*iterative II (learn from solution)*/
	bool isValidBST(TreeNode* root) {
		if (!root) return true;
		stack<TreeNode*> s;
		TreeNode* prev = nullptr;

		while (root || !s.empty()) {
			while (root) {
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			if (prev && prev->val >= root->val) return false;
			prev = root;

			root = root->right;
		}

		return true;
	}

	/*iterative*/
	/*AC 1549*/
	//     bool isValidBST(TreeNode* root) {
	//         stack<TreeNode*> s;

	//         TreeNode* prev = nullptr;
	//         s.push(root);

	//         while(!s.empty()) {
	//             TreeNode* curr = s.top();
	//             s.pop();
	//             if (!curr) continue;

	//             if (!s.empty() && curr->right == s.top()) { //visit
	//                 if (prev && prev->val >= curr->val) return false;
	//                 prev = curr;
	//                 continue;
	//             }

	//             s.push(curr->right);
	//             s.push(curr);
	//             s.push(curr->left);
	//         }
	//         return true;
	//     }

	/*remove INT_MIN, INT_MAX*/
	//     bool inorder(TreeNode* root, TreeNode*& prev) {
	//         if (!root) return true;
	//         if (root->left)
	//             if (!inorder(root->left, prev)) return false;
	//         if (prev && root->val <= prev->val) return false;
	//         prev = root;
	//         if (root->right)
	//             if (!inorder(root->right, prev)) return false;
	//         return true;
	//     }

	//     bool isValidBST(TreeNode* root) {
	//         TreeNode* prev = nullptr;
	//         return inorder(root, prev);
	//     }


	/*20170824 1430*/
	/*         1440*/
	//     bool inorder(TreeNode* root, long & last) {
	//         if (!root) return true;
	//         if (root->left)
	//             if (!inorder(root->left, last)) return false;
	//         if (root->val <= last) return false;
	//         last = root->val;
	//         if (root->right)
	//             if (!inorder(root->right, last)) return false;
	//         return true;
	//     }

	//     bool isValidBST(TreeNode* root) {
	//         long last = LLONG_MIN;
	//         return inorder(root, last);
	//     }

	/* 1) Remove INT_MIN INT_MAX 2) *& 3) Inorder traverse */
};
