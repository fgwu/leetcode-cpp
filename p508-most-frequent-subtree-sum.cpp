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
	/*20170521 0129*/
	/*         0147*/
	/*AC       0156*/
	int calcSum(TreeNode* n, unordered_map<int, int>& map) {
		if (!n) return 0;
		int sum = n->val + calcSum(n->left, map) + calcSum(n->right, map);
		if (map.find(sum) == map.end())
			map[sum] = 1;
		else
			map[sum]++;
		return sum;
	}
	vector<int> findFrequentTreeSum(TreeNode* root) {
		unordered_map<int, int> map; //sum -> cnt
		vector<int> rv;
		int curr_cnt = INT_MIN;
		if (!root) return rv;
		calcSum(root, map);
		for (const auto & entry:map) {
			if (entry.second < curr_cnt) continue;
			if (entry.second == curr_cnt) {
				rv.push_back(entry.first);
				continue;
			}
			curr_cnt = entry.second;
			rv.clear();
			rv.push_back(entry.first);
		}
		return rv;
	}
};
