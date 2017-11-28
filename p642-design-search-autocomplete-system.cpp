class AutocompleteSystem {
	struct TrieNode {
		int cnt;
		string s;
		map<char, TrieNode*> m;
		TrieNode(): cnt(0){}
		TrieNode(int i): cnt(i){}
	};

	TrieNode *root;
	string query;

	void dfs(vector<pair<int, string>> & pv, TrieNode *curr) {
		if (curr->cnt)
			pv.emplace_back(curr->cnt, curr->s);
		for (auto p: curr->m) {
			if (!p.second) continue;
			dfs(pv, p.second);
		}
	}

	TrieNode* add(string s) {
		TrieNode * curr = root;
		for (auto c: s) {
			if (!curr->m.count(c))
				curr->m[c] = new TrieNode();
			curr = curr->m[c];
		}
		curr->cnt++;
		curr->s = s;
		return curr;
	}

	TrieNode* add(string s, int i) {
		TrieNode * curr = root;
		for (auto c: s) {
			if (!curr->m.count(c))
				curr->m[c] = new TrieNode();
			curr = curr->m[c];
		}
		curr->cnt = i;
		curr->s = s;
		return curr;
	}

	vector<string> find(string s) {
		vector<pair<int, string>> pv;
		vector<string> rv;
		TrieNode* curr = root;
		for (auto c: s) {
			if (!curr->m.count(c))
				return rv;
			curr = curr->m[c];
		}

		dfs(pv, curr);

		auto cmp = [](const pair<int, string> & a, const pair<int, string> &b){
			if (a.first == b.first) return a.second < b.second;
			return a.first > b.first;
		};
		sort(pv.begin(), pv.end(), cmp);
		for (auto &p: pv) {
			rv.push_back(p.second);
			if (rv.size() == 3) break;
		}
		return rv;
	}

public:
	/*20171127 2157*/
	/*AC       2245*/
	AutocompleteSystem(vector<string> sentences, vector<int> times) {
		assert(sentences.size() == times.size());
		int n = times.size();
		root = new TrieNode();
		for (int i = 0; i < n; i++)
			TrieNode * curr = add(sentences[i], times[i]);
	}

	vector<string> input(char c) {
		if (c == '#') {
			add(query);
			query.clear();
			return vector<string>();
		}
		query += c;
		return find(query);
	}
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
