class Solution {
public:
	/*20171119 0905 bfs*/
	/*AC       0930*/
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int rv = 0;
		if (beginWord.size() != endWord.size()) return 0;

		unordered_set<string> unvisited;
		for(auto & w: wordList) unvisited.insert(w);

		vector<string> frontier, next;
		frontier.push_back(beginWord);
		while(!frontier.empty()) {
			rv++;
			for (auto& w: frontier) {
				if (w == endWord) return rv;

				for (int i = 0; i < w.size(); i++){
					for (char c = 'a'; c <= 'z'; c++) {
						if (w[i] == c) continue;
						swap(w[i], c);
						if (unvisited.count(w)) {
							next.push_back(w);
							unvisited.erase(w);
						}
						swap(w[i], c);
					}
				}
			}
			swap(frontier, next);
			next.resize(0);
		}

		return 0;
	}
};
