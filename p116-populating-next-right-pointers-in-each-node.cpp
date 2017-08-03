/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	/*so, recursive is not purely constant space. try again.*/
	/*AC 2258*/
	void connect(TreeLinkNode *root) {
		for (; root; root = root->left) {
			for (TreeLinkNode* cur = root; cur; cur = cur->next) {
				if (!cur->left || !cur->right) continue;
				cur->left->next = cur->right;
				// printf("%d->%d\n", cur->left->val, cur->right->val);
				cur->right->next = cur->next? cur->next->left: nullptr;
				// printf("%d->%d\n", cur->right->val, cur->next? cur->next->left->val: 0);
			}
		}
	}

	/*20170725*/
	/*AC 1416*/
	// void connect(TreeLinkNode *root) {
	//     if (!root) return;
	//     if (root->left) connect(root->left);
	//     if (root->right) connect(root->right);
	//     TreeLinkNode* ln = root->left, *rn = root->right;
	//     while(ln && rn) {
	//         ln->next = rn;
	//         ln = ln->right;
	//         rn = rn->left;
	//     }
	// }
};
