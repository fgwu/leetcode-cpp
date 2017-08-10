class Trie {
public:
	/*20170810 1625*/
	/*AC 20170810 1632*/
	struct TrieNode {
		unordered_map<char, TrieNode*> child;
		bool isWord = false;
	};

	TrieNode *root;

	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* tmp = root;
		for(auto c: word) {
			if (!tmp->child.count(c)) tmp->child[c] = new TrieNode();
			tmp = tmp->child[c];
		}
		tmp->isWord = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* tmp = root;
		for(auto c: word) {
			if (!tmp->child.count(c)) return false;
			tmp = tmp->child[c];
		}
		return tmp->isWord;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode* tmp = root;
		for(auto c: prefix) {
			if (!tmp->child.count(c)) return false;
			tmp = tmp->child[c];
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
