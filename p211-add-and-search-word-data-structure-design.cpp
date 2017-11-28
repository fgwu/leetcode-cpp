class WordDictionary {
public:
	/*20171124 1050*/
	/*         1109*/
	/*AC       1118*/
	struct TrieNode {
		bool word;
		vector<TrieNode*> child;
		TrieNode(bool w): word(w){child.resize(26, nullptr);}
	};

	TrieNode *root;

	/** Initialize your data structure here. */
	WordDictionary() {
		root = new TrieNode(false);
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		auto curr = root;
		for (int i = 0; i < word.size(); curr = curr->child[word[i++] - 'a'])
			if (!curr->child[word[i] - 'a']) curr->child[word[i] - 'a'] = new TrieNode(false);

		curr->word = true;
	}

	bool search(TrieNode *curr, string& word, int pos) {
		if (pos == word.size()) return curr->word;
		if (word[pos] != '.')
			return curr->child[word[pos] - 'a'] && search(curr->child[word[pos] - 'a'], word, pos + 1);
		for (int i = 0; i < 26; i++)
			if (curr->child[i] && search(curr->child[i], word, pos + 1)) return true;
		return false;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return search(root, word, 0);
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
