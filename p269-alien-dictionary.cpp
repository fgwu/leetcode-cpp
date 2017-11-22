class Solution {
public:
	/*20171120 0108*/
	/*AC       0936*/
	string alienOrder(vector<string>& words) {
		int pos = 0;
		vector<string> tmp;
		unordered_map<char, vector<char>> g;
		unordered_map<char, int> indegree;
		queue<char> q;
		string rv;

		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].size(); j++)
				if (!g.count(words[i][j])) g[words[i][j]] = vector<char>();

			if (!i) continue;

			for (int j = 0; j < words[i - 1].size() && j < words[i].size(); j++){
				if (words[i - 1][j] == words[i][j]) continue;
				g[words[i - 1][j]].push_back(words[i][j]);
				if (indegree.count(words[i][j]))
					indegree[words[i][j]]++;
				else
					indegree[words[i][j]] = 1;
				break;
			}
		}

		for (auto &p : g){
			if (indegree.count(p.first)) {
				if (!indegree[p.first]) q.push(p.first);
			} else
				q.push(p.first);
		}

		while(!q.empty()) {
			char c = q.front();
			q.pop();
			rv += c;
			for (auto nbr: g[c])
				if (!--indegree[nbr]) q.push(nbr);
		}

		if (rv.size() == g.size()) return rv;
		return "";
	}
};
