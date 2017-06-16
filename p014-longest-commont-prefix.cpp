class Solution {
public:
	/*20170614 2337*/
	/*AC       2344*/
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";
		if (!strs.size()) return res;
		for (int i = 0; ; i++) {
			for (int j = 0; j < strs.size(); j++) {
				if (i >= strs[j].size()) return res;
				if (j == 0 || strs[j][i] == strs[j - 1][i]) continue;
				return res;
			}
			res += strs[0][i];
		}
		return res;
	}
};
