class Solution {
public:
	/*20170609 1114*/
	/*AC       1120*/
	/*Note: two way mapping. the target should be unique. */
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size()) return false;
		unordered_map<char, char> m;
		unordered_set<char> found;
		for (int i = 0; i < s.size(); i++) {
			if (!m.count(s[i])) {
				if (found.count(t[i])) return false;
				found.insert(t[i]);
				m[s[i]] = t[i];
				continue;
			}
			if (m[s[i]] != t[i]) return false;
		}
		return true;
	}

	/*20170609 1050*/
	/*wrong answer. solving a different problem ....*/
	// bool isIsomorphic(string s, string t) {
	//     vector<int> sv(128, 0), tv(128, 0);
	//     for (const auto c:s) sv[c]++;
	//     for (const auto c:t) tv[c]++;
	//     sort(sv.begin(), sv.end());
	//     sort(tv.begin(), tv.end());
	//     for (int i = 0; i < 128; i++) if (sv[i] != tv[i]) return false;
	//     return true;
	// }
};
