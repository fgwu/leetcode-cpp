class Solution {
public:
	/*try prefix tree */
	/*AC    0006*/
	class TrieNode {
	public:
		unordered_map<char, TrieNode*> child;
		bool isWord = false;
	};

	TrieNode* buildTrie(vector<string>& wordDict) {
		TrieNode* root = new TrieNode();
		for(auto & word: wordDict) {
			TrieNode* tmp = root;
			for(int i = 0; i < word.size(); i++) {
				char c = word[i];
				if (!tmp->child.count(c))
					tmp->child[c] = new TrieNode();
				tmp = tmp->child[c];
			}
			tmp->isWord = true;
		}
		return root;
	}

	void tryMatch(string &s, TrieNode* root, int start, vector<bool>& dp) {
		TrieNode* tmp = root;
		for (int i = start; i < s.size(); i++) {
			char c = s[i];
			if (!tmp->child.count(c)) return;
			tmp = tmp->child[c];
			if (tmp->isWord)
				dp[i] = true;
		}
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		assert(!s.empty());

		TrieNode *root = buildTrie(wordDict);

		int n = s.size();
		vector<bool> dp(n, false);
		for (int i = 0; i < n; i++) {
			if (i > 0 && !dp[i - 1]) continue;
			tryMatch(s, root, i, dp);
		}
		return dp[s.size() - 1];
	}


	/*20170809 2248*/
	//     void tryMatch(string &s, vector<string>& wordDict, int start, vector<bool>& dp) {
	//         for (int len = 1; len + start <= s.size(); len++) {
	//             if (dp[start + len - 1]) continue;
	//             string tmp = s.substr(start, len);
	//             // printf("tmp=%s\n", tmp.c_str());
	//             for (auto &word: wordDict) {
	//                 // printf("    word=%s", tmp.c_str());
	//                 if (tmp == word)
	//                     dp[start + len - 1] = true;
	//                 // printf(" dp[%d]=%s\n", start + len - 1, dp[start + len - 1]? "true": "false");
	//             }
	//         }
	//     }

	//     bool wordBreak(string s, vector<string>& wordDict) {
	//         assert(!s.empty());
	//         int n = s.size();
	//         vector<bool> dp(n, false);
	//         for (int i = 0; i < n; i++) {
	//             if (i > 0 && !dp[i - 1]) continue;
	//             tryMatch(s, wordDict, i, dp);
	//         }
	//         return dp[s.size() - 1];
	//     }
};
