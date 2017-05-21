class Solution {
public:
	/*20170520 1938*/
	/*AC       1941*/
	bool isAnagram(string s, string t) {
		vector<int> map(26, 0);
		for (const auto & c: s) map[c - 'a']++;
		for (const auto & c: t) map[c - 'a']--;
		for (const auto & cnt:map) if (cnt) return false;
		return true;
	}
};
