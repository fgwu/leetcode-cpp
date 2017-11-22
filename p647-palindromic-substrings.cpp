class Solution {
public:
	/*20171119 2344*/
	/*AC       2348*/
	int countSubstrings(string s) {
		int rv = 0;
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; i - j >= 0 && i + j < s.size() && s[i - j] == s[i + j]; j++) rv++;
			for (int j = 0; i - j >= 0 && i + j + 1 < s.size() && s[i - j] == s[i + j + 1]; j++) rv++;
		}
		return rv;
	}
};
