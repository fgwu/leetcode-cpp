class Solution {
public:
	/*2D D     2040*/
	/*AC       2123*/
	bool isMatch(string s, string p) {
		vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, false));
		for (int i = 0; i <= s.size(); i++) {
			for (int j = 0; j <= p.size(); j++) {
				if (!i && !j) {
					dp[i][j] = true;
					continue;
				}

				if (!j) {
					dp[i][j] = false;
					continue;
				}

				if (!i) {
					dp[i][j] = p[j - 1] == '*' && dp[i][j - 1];
					continue;
				}


				if (isalpha(p[j - 1])) {
					dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
					continue;
				}

				if (p[j - 1] == '?') {
					dp[i][j] = dp[i - 1][j - 1];
					continue;
				}

				for (int k = 0; k <= i; k++) {
					dp[i][j] |= dp[k][j - 1];
					if (dp[i][j]) break;
				}
			}
		}

		// for (int i = 0; i <= s.size(); i++) {
		//     for (int j = 0; j <= p.size(); j++) {
		//         cout << (dp[i][j] ? 'T' : 'F');
		//     }
		//     cout << "\n";
		// }
		return dp[s.size()][p.size()];
	}

	/*20171120 2207*/
	/*TLE      2235*/
	//     bool isMatch(string &s, string &p, int si, int pi) {
	//         if (si == s.size() && pi == p.size()) return true;
	//         if (pi == p.size()) return false;
	//         if (isalpha(p[pi])) {
	//             if (si < s.size() && s[si] == p[pi])
	//                 return isMatch(s, p, si + 1, pi + 1);
	//             return false;
	//         }

	//         if (p[pi] == '?') {
	//             if (si < s.size())
	//                 return isMatch(s, p, si + 1, pi + 1);
	//             return false;
	//         }

	//         int i;
	//         for (int i = si; i <= s.size(); i++) {
	//             // if (i > si + 1 && s[i - 1] != s[si]) break;
	//             if (isMatch(s, p, i, pi + 1)) return true;
	//         }
	//         return false;
	//     }

	//     // "" "", "" "*",
	//     bool isMatch(string s, string p) {
	//         return isMatch(s, p, 0, 0); // matching from the first
	//     }
};
