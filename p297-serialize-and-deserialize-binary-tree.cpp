/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	/*20170915 1110*/
	/*20171119 2345 restart*/
	/*AC       0930*/
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (!root) return "#";
		return to_string(root->val) + "|" + serialize(root->left) + serialize(root->right);
	}

	TreeNode* dfs(string& data, int& pos) {
		assert(pos < data.size());
		if (data[pos] == '#') return nullptr;
		int num_ends = data.find_first_of('|', pos);
		int val = stoi(data.substr(pos, num_ends-pos));
		TreeNode *root = new TreeNode(val);
		pos = num_ends;
		root->left = dfs(data, ++pos);
		root->right = dfs(data, ++pos);
		return root;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int pos = 0;
		cout << data << "\n";
		return dfs(data, pos);
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
