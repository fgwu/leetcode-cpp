class Solution {
public:
	/*20170608 1532*/
	/*AC       1550*/
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if (s.size() < p.size()) return res;
		unordered_map<char, int> m;
		for (const auto & c:p) m[c]++;
		int cnt = m.size();

		for (int i = 0; i < s.size(); i++) {
			char end = s[i];
			if (!m[end]) cnt++;
			m[end]--;
			if (!m[end]) cnt--;
			if (i == p.size() - 1 && !cnt) res.push_back(0);
			if (i < p.size()) continue;

			char start = s[i - p.size()];
			if (!m[start]) cnt++;
			m[start]++;
			if (!m[start]) cnt--;
			if (!cnt) res.push_back(i - p.size() + 1);
		}
		return res;
	}

	/*20170608 1506*/
	/*time exceed*/
	// vector<int> findAnagrams(string s, string p) {
	//     vector<int> res;
	//     if (s.size() < p.size()) return res;
	//     sort(p.begin(), p.end());
	//     for (int i = 0; i <= s.size() - p.size(); i++) {
	//         string cand = s.substr(i, p.size());
	//         sort(cand.begin(), cand.end());
	//         // cout << cand << " " << p << "\n";
	//         if(cand == p) res.push_back(i);
	//     }
	//     return res;
	// }
};
