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
	/*AC 2124 no swap root*/
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root) return root;

		if (root->val > key) { // go left
			root->left = deleteNode(root->left, key);
			return root;
		}

		if (root->val < key) { // go right
			root->right = deleteNode(root->right, key);
			return root;
		}

		//delete
		if (!root->left) {
			TreeNode *tmp = root->right;
			delete root;
			return tmp;
		}

		if (!root->right) {
			TreeNode *tmp = root->left;
			delete root;
			return tmp;
		}

		// find the rightmost of left subtree
		TreeNode *newroot = root->left;

		if (!newroot->right) {
			newroot->right = root->right;
			delete root;
			return newroot;
		}

		TreeNode *newrootparent = newroot;
		newroot = newroot->right;

		while(newroot->right) {
			newrootparent = newroot;
			newroot = newroot->right;
		}

		newrootparent->right = newroot->left;
		newroot->left = root->left;
		newroot->right = root->right;
		delete root;

		return newroot;
	}



	/*20170925 2057*/
	/*AC       2113*/
	//     TreeNode* deleteNode(TreeNode* root, int key) {
	//         if (!root) return root;

	//         if (root->val > key) { // go left
	//             root->left = deleteNode(root->left, key);
	//             return root;
	//         }

	//         if (root->val < key) { // go right
	//             root->right = deleteNode(root->right, key);
	//             return root;
	//         }

	//         //delete
	//         if (!root->left) {
	//             TreeNode *tmp = root->right;
	//             delete root;
	//             return tmp;
	//         }

	//         if (!root->right) {
	//             TreeNode *tmp = root->left;
	//             delete root;
	//             return tmp;
	//         }

	//         // find the rightmost of left subtree
	//         TreeNode *newroot = root->left;
	//         while(newroot->right) newroot = newroot->right;

	//         int newrootval = newroot->val;

	//         root->left = deleteNode(root->left, newrootval);
	//         root->val = newrootval;
	//         return root;
	//     }
};
