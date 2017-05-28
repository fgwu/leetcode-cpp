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
	/*20170524 0031*/
	/*AC       0056*/
	TreeNode* makeTree(vector<int>& nums, int start, int end) {
		if (start >= end) return nullptr;
		int mid = (start + end) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = makeTree(nums, start, mid);
		root->right = makeTree(nums, mid + 1, end);
		return root;
	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return makeTree(nums, 0, nums.size());
	}
};
