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
	/*20170519 15:42*/
	/*         16:43*/
	/*AC       16:45*/
	/*Note: When about to finish or donno what to do, read the problem */
	int findTilt(TreeNode* root) {
		int s, t;
		runRec(root, &s, &t);
		return t;
	}

	void runRec(TreeNode* n, int *sum, int *tilt){
		if (!n) {
			*sum = 0;
			*tilt = 0;
			return;
		}

		int sleft, sright, tleft, tright;
		runRec(n->left, &sleft, &tleft);
		runRec(n->right, &sright, &tright);
		*sum = sleft + sright + n->val;
		*tilt = abs(sleft - sright) + tleft + tright;
	}
};
