class Solution {
public:
	/*20170926 2138*/
	/*AC       2214*/
	bool checkInclusion(string s1, string s2) {
		int l1 = s1.size(), l2 = s2.size();
		if (!l1) return true;
		unordered_map<char, int> m;
		for(auto c: s1)
			m[c]++;

		int zero_cnt = 0;
		for (int i = 0; i < l2; i++) {
			if (m.count(s2[i])) {
				if (!m[s2[i]]) zero_cnt--;
				m[s2[i]]--;
				if (!m[s2[i]]) zero_cnt++;
			}

			if (i - l1 >= 0 && m.count(s2[i - l1])) {
				if (!m[s2[i - l1]]) zero_cnt--;
				m[s2[i - l1]]++;
				if (!m[s2[i - l1]]) zero_cnt++;
			}
			if (zero_cnt == m.size()) return true;
		}

		return false;
	}
};
