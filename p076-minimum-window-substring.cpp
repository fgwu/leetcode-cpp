class Solution {
public:
	/*AC 2358 reduce to O(n)*/
	string minWindow(string s, string t) {
		if (!t.size()) return "";
		unordered_map<char, int>m;
		for (auto c: t) m[c]++;
		int minlen = s.size() + 1;
		int minstart = 0;
		int cnt = 0;
		for (int i = 0, j = 0; i <= j && j <= s.size();) {
			if (cnt == m.size()) {
				if (j - i < minlen) {
					minlen = j - i;
					minstart = i;
				}
				if (m.count(s[i])) {
					if (!m[s[i]]) cnt--;
					m[s[i]]++;
				}
				i++;
			} else {
				if (m.count(s[j])) {
					m[s[j]]--;
					if (!m[s[j]]) cnt++;
				}
				j++;
			}
		}
		return minlen > s.size()? "": s.substr(minstart, minlen);
	}


	/*20170926 2259*/
	/*AC       2349*/
	//     bool satisfy(unordered_map<char, int>m) {
	//         for (auto & p:m)
	//             if (p.second > 0) return false;
	//         return true;
	//     }

	//     string minWindow(string s, string t) {
	//         if (!t.size()) return "";
	//         unordered_map<char, int>m;
	//         for (auto c: t) m[c]++;
	//         int minlen = s.size() + 1;
	//         string res = "";
	//         for (int i = 0, j = 0; i <= j && j <= s.size();) {
	//             if (satisfy(m)) {
	//                 if (j - i < minlen) {
	//                     minlen = j - i;
	//                     res = s.substr(i, minlen);
	//                 }
	//                 if (m.count(s[i])) m[s[i]]++;
	//                 i++;
	//             } else {
	//                 if (m.count(s[j])) m[s[j]]--;
	//                 j++;
	//             }
	//         }
	//         return res;
	//     }
};
