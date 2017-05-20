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
	/*20170519 18:22 BST!!! Reading problem*/
	/*AC       18:33*/
	int minDiff = INT_MAX;
	int prev = -1;
	int getMinimumDifference(TreeNode* root) {
		if (!root) return minDiff;
		getMinimumDifference(root->left);
		if (prev != -1) minDiff = min(minDiff, root->val - prev);
		prev = root->val;
		getMinimumDifference(root->right);
		return minDiff;
	}




	/*20170519 18:06*/
	/*         18:16*/
	/*AC       18:20*/
	// int getMinimumDifference(TreeNode* root) {
	//     vector<int> values, &ref = values;
	//     int mindiff, i;
	//     traverse(root, ref);
	//     sort(values.begin(), values.end());
	//     if (values.size() == 0 || values.size() == 1) return 0;

	//     mindiff = values[1] - values[0];
	//     for (i = 2; i < values.size(); i++){
	//         if (values[i] - values[i-1] < mindiff){
	//             mindiff = values[i] - values[i - 1];
	//         }
	//     }
	//     return mindiff;
	// }

	// void traverse(TreeNode* n, vector<int> &v){
	//     if (!n) return;
	//     v.push_back(n->val);
	//     traverse(n->left, v);
	//     traverse(n->right, v);
	// }
};
