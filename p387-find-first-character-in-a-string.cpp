class Solution {
public:
	/*20170520 0305*/
	/*         0311*/
	/*AC       0312 bugfree*/
	int firstUniqChar(string s) {
		int i;
		vector<int> map(26, 0);
		for (const auto & c:s) map[c - 'a']++;
		for (i = 0; i<s.size(); i++) if (map[s[i] - 'a'] == 1) return i;
		return -1;
	}
};
