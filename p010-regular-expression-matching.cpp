class Solution {
public:
	/*20171118 1728*/
	/*AC       1759*/
	bool isMatch(string s, string p) {
		if (!s.size() && !p.size()) return true;
		if (!p.size()) return false;

		if (p.size() > 1 && p[1] == '*') {
			if (p[0] == '.') {
				for (int i = 0; i <= s.size(); i++) {
					if (isMatch(s.substr(i), p.substr(2))) return true;
				}
				return false;
			}

			for (int i = 0; i <= s.size(); i++) {
				if (i && s[i - 1] != p[0]) break;
				if (isMatch(s.substr(i), p.substr(2))) return true;
			}
			return false;
		}
		if (p[0] == '.')
			return s.size() && isMatch(s.substr(1), p.substr(1));

		return s.size() && s[0] == p[0] && isMatch(s.substr(1), p.substr(1));
	}
};
