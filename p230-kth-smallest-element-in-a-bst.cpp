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
	/*for more simiplicity */
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*> s;
		s.push(root);
		while(!s.empty()) {
			TreeNode* tmp = s.top();
			s.pop();
			if (!tmp) continue;
			// check whether it's the second visit
			if (!s.empty() && tmp->right == s.top()){
				if (!--k) return tmp->val;
				continue;
			}
			s.push(tmp->right);
			s.push(tmp);
			s.push(tmp->left);
		}
		return -1;
	}

	/* Actually here we can use iterative InOrder Traversal*/
	/*AC   1549*/
	//     int kthSmallest(TreeNode* root, int k) {
	//         stack<TreeNode*> s;
	//         s.push(root);
	//         while(!s.empty()) {
	//             TreeNode* tmp = s.top();
	//             s.pop();
	//             if (!tmp) continue;
	//             // check whether its first poped
	//             if (s.empty() || tmp->right != s.top()) {
	//                 s.push(tmp->right);
	//                 s.push(tmp);
	//                 s.push(tmp->left);
	//                 continue;
	//             }
	//             if(--k == 0) return tmp->val;
	//         }
	//         return -1;
	//     }

	/*20170706 1519*/
	/*AC       1528*/
	//     void inOrder(TreeNode* root, int& k, bool& found, int& res) {
	//         if (!root || found) return;
	//         if (root->left) inOrder(root->left, k, found, res);
	//         if (found) return;
	//         if (--k == 0) {
	//             found = true;
	//             res = root->val;
	//             return;
	//         }
	//         if (root->right) inOrder(root->right, k, found, res);
	//     }

	//     int kthSmallest(TreeNode* root, int k) {
	//         int res = -1;
	//         bool found = false;
	//         inOrder(root, k, found, res);
	//         return res;
	//     }
};
