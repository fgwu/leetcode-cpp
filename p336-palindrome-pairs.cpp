struct TrieNode {
	int idx;
	unordered_map<char, TrieNode*>child;
	TrieNode() {
		idx = -1; // invalid word
	}
};

/*AC  20171112 2223*/
class Solution {
	TrieNode forward_trie;
	TrieNode backward_trie;

	void add_word(vector<string>& words, int idx) {
		string w = words[idx];
		TrieNode *fp = &forward_trie, *bp = &backward_trie;
		for (int i = 0; i <= w.size(); i++) {
			if (i == w.size()){
				fp->idx = idx;
				break;
			}

			if (!fp->child.count(w[i])) {
				fp->child[w[i]] = new TrieNode();
			}

			fp = fp->child[w[i]];
		}

		for (int i = w.size() - 1; i >= -1; i--) {
			if (i == -1) {
				bp->idx = idx;
				break;
			}
			if (!bp->child.count(w[i])) {
				bp->child[w[i]] = new TrieNode();
			}

			bp = bp->child[w[i]];
		}
	}

	void check_word(vector<string>& words, int idx, vector<vector<int>>& rv){
		string w = words[idx];
		// printf("idx=%d, %s\n", idx, w.c_str());
		TrieNode *fp = &forward_trie, *bp = &backward_trie;
		for (int i = 0; i <= w.size(); i++) {
			//             if (i == w.size()) {
			//                 if (bp->idx != -1 && bp->idx != idx) {
			//                     printf("bp added %d, %d\n", idx, bp->idx);
			//                     rv.push_back(vector<int>{idx, bp->idx});
			//                     break;
			//                 }
			//             }

			if (bp->idx != -1) {
				bool palin = true;
				for (int k = 0; i + k < w.size() - 1 - k; k++) {
					if (w[i + k] != w[w.size() - 1 - k]) {
						palin = false;
						break;
					}
				}
				if (palin && bp->idx != idx) {
					// printf("bp added %d, %d\n", idx, bp->idx);
					rv.push_back(vector<int>{idx, bp->idx});
				}
			}

			if (i < w.size() && bp->child[w[i]])
				bp = bp->child[w[i]];
			else
				break;
		}

		for (int i = w.size() - 1; i >= 0; i--) {
			if (fp->idx != -1) {
				bool palin = true;
				for (int k = 0; k < i - k; k++) {
					// printf("->w[%d]=%c, w[%d]=%c\n", i, w[i], i - k, w[i -k]);
					if (w[k] != w[i - k]) {
						palin = false;
						break;
					}
				}
				if (palin && fp->idx != idx) {
					// printf("fp added %d, %d\n", fp->idx, idx);
					rv.push_back(vector<int>{fp->idx, idx});
				}
			}

			// printf("checking fp->child[%c]=%d\n", w[i], fp->child[w[i]]);
			if (fp->child[w[i]])
				fp = fp->child[w[i]];
			else
				break;
		}
	}

public:
	/*20171112 1827*/
	vector<vector<int>> palindromePairs(vector<string>& words) {
		for (int i = 0; i < words.size(); i++) {
			add_word(words, i);
		}

		vector<vector<int>> rv;
		for (int i = 0; i < words.size(); i++) {
			check_word(words, i, rv);
		}

		return rv;
	}
};

/*MLE*/
// struct TrieNode {
//     int idx;
//     vector<TrieNode *> child;
//     TrieNode() {
//         idx = -1; // invalid word
//         child.resize(26, nullptr);
//     }
// };

// class Solution {
//     TrieNode forward_trie;
//     TrieNode backward_trie;

//     void add_word(vector<string>& words, int idx) {
//         string w = words[idx];
//         TrieNode *fp = &forward_trie, *bp = &backward_trie;
//         for (int i = 0; i <= w.size(); i++) {
//             if (i == w.size()){
//                 fp->idx = idx;
//                 break;
//             }

//             int pos = w[i] - 'a';
//             if (!fp->child[pos]) {
//                 fp->child[pos] = new TrieNode();
//             }

//             fp = fp->child[pos];
//         }

//         for (int i = w.size() - 1; i >= -1; i--) {
//             if (i == -1) {
//                 bp->idx = idx;
//                 break;
//             }
//             int pos = w[i] - 'a';
//             if (!bp->child[pos](vector<int>{idx, bp->idx});
// //                  ; k++) {
//                     // printf("->w[%d]=%c, w[%d]=%c\n", i, w[i], i - k, w[i -k]);
//                     ifsize(); i++) {
//             check_word(words, i, rv);
//         }

//         return rv;
//     }
// };
