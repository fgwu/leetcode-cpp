class Solution {
public:
	/* seen hashmap solution */
	/*AC 20170531 2225*/
	// int findMaximumXOR(vector<int>& nums) {
	//     int res = 0, mask = 0;
	//     for (int i = 31; i >= 0; i--) {
	//         mask |= 1 << i;
	//         unordered_set<int> s;
	//         for (const auto n:nums) s.insert(n & mask);
	//         int tmp = res | 1 << i;
	//         for (const auto prefix: s)
	//             if (s.count(prefix ^ tmp)) {res = tmp; break;}
	//     }
	//     return res;
	// }

	/*AC 20170531 2234*/
	/*optimized version*/
	struct TrieNode {
		vector<TrieNode*> child;
		TrieNode() {child.resize(2, nullptr); }
	};

	int findMaximumXOR(vector<int>& nums) {
		int res = INT_MIN;
		TrieNode root, *p;
		for (const auto & n:nums) {
			p = &root;
			for (int i = 31; i>=0; i--) {
				int idx = n >> i & 1;
				if (!p->child[idx]) p->child[idx] = new TrieNode();
				p = p->child[idx];
			}
		}

		for (const auto & n:nums) {
			p = &root;
			int tmp = 0;
			for (int i = 31; i >= 0; i--) {
				int idx = (n >> i & 1) ^ 1;
				if (p->child[idx]) { p = p->child[idx]; tmp |= 1 << i; }
				else p = p->child[idx ^ 1];
				res = max(res, tmp);
			}
		}
		return res;
	}

	/*AC 20170531 2157*/
	// struct TrieNode {
	//     vector<TrieNode*> child;
	//     TrieNode() {child.resize(2, nullptr); }
	// };
	// int findMaximumXOR(vector<int>& nums) {
	//     int res = INT_MIN;
	//     TrieNode root, *p;
	//     for (const auto & n:nums) {
	//         p = &root;
	//         for (int i = 31; i>=0; i--) {
	//             int mask = 1 << i;
	//             if (n & mask) {
	//                 if (!p->child[1]) p->child[1] = new TrieNode();
	//                 p = p->child[1];
	//             } else {
	//                 if (!p->child[0]) p->child[0] = new TrieNode();
	//                 p = p->child[0];
	//             }
	//         }
	//     }

	//     for (const auto & n:nums) {
	//         p = &root;
	//         int tmp = 0;
	//         for (int i = 31; i >= 0; i--) {
	//             int mask = 1 << i;
	//             if (n & mask) { // 1, look for 0
	//                 if (p->child[0]) {
	//                     p = p->child[0];
	//                     tmp += mask;
	//                 } else
	//                     p = p->child[1];
	//             } else {
	//                 if (p->child[1]) {
	//                     p = p->child[1];
	//                     tmp += mask;
	//                 } else
	//                     p = p->child[0];
	//             }
	//             res = max(res, tmp);
	//         }
	//     }
	//     return res;
	// }

	/*AC finally 20170531 1632*/
	// struct TreeNode {
	//     TreeNode* left;
	//     TreeNode* right;
	//     int val; // -1 empty
	//     int shift;
	//     TreeNode(): left(nullptr), right(nullptr), val(-1){}
	//     TreeNode(int v): left(nullptr), right(nullptr), val(v){}
	// };

	// TreeNode* insert(TreeNode& root, int n){
	//     TreeNode* p = &root;
	//     for (int i = 31; i >= 0; i--) {
	//         int mask = 1 << i;
	//         if(n & mask) { //right
	//             if (!p->right) p->right = new TreeNode();
	//             p =  p->right;
	//         } else { //left
	//             if (!p->left) p->left = new TreeNode();
	//             p = p->left;
	//         }
	//         if (i == 0) p->val = n;
	//         p->shift = i;
	//     }
	//     return p;
	// }


	// void dfs(TreeNode*root) {
	//     if (!root) return;
	//     dfs(root->left);
	//     if (root->val != -1) cout << "visited " << root->val << "\n";
	//     dfs(root->right);
	// }

	// int findRec(TreeNode* t1, TreeNode* t2) {
	//     if (!t1 || !t2) return 0;
	//     if (t1->val != -1 && t2->val != -1) return 0;
	//     if (t1->val != -1 || t2->val != -1) exit(EXIT_FAILURE);
	//     if ((t1->left && t2->right) ||(t1->right && t2->left)){
	//         int a = findRec(t1->left, t2->right), b = findRec(t1->right, t2->left);
	//         int weight =(1 << (t1->shift-1));
	//         return weight + max(a, b);
	//     } else {
	//         if (t1->left && t2->left) return findRec(t1->left, t2->left);
	//         return findRec(t1->right, t2->right);
	//     }
	// }


	// int findMaximumXOR(vector<int>& nums) {
	//     TreeNode root, *p = &root;
	//     for (const auto & n:nums) insert(root, n);
	//     // dfs(&root);
	//     return findRec(p, p);
	// }

};
