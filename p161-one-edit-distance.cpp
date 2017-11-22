class Solution {
public:
	/*AC  1125*/
	bool isOneEditDistance(string s, string t) {
		int m = s.size(), n = t.size();
		if (m - n > 1 || n - m > 1) return false;
		if (!m && !n) return false;
		if (!m || !n) return true;

		int left = 0, up = 0, diag = 0;

		for (int i = 1; i <= m || i <= n; i++) {
			// left dp[i][i - 1], s[i - 1] t[i - 2]
			if (i == 1) {
				left = 1;
				up = 1;
			}
			else {
				if (i - 1 < m && i - 2 < n && s[i - 1] != t[i - 2])
					left = min(left, diag) + 1;
				if (i - 2 < m && i - 1 < n && s[i - 2] != t[i - 1])
					up = min(up, diag) + 1;
			}

			if (i - 1 < m && i - 1 < n && s[i - 1] != t[i - 1])
				diag = min(diag, min(up, left)) + 1;

			printf("i=%d up=%d left=%d diag=%d\n", i, up, left, diag);
		}

		if (m == n) return diag == 1;
		if (m == n - 1) return up == 1;
		return left == 1;
	}


	/*MLE   1103*/
	//     bool isOneEditDistance(string s, string t) {
	//         int m = s.size(), n = t.size();
	//         if (m - n > 1 || n - m > 1) return false;
	//         if (!m && !n) return false;
	//         if (!m || !n) return true;

	//         vector<vector<int>>dp(m + 1, vector<int>(n + 1, m + n));

	//         for (int i = 0; i <= m; i++) {
	//             for (int j = max(0, i - 1); j <= i + 1; j++) {
	//                 if (!i) {
	//                     dp[i][j] = j;
	//                     continue;
	//                 }

	//                 if (!j) {
	//                     dp[i][j] = i;
	//                     continue;
	//                 }

	//                 if (s[i - 1] == t[j - 1]) {
	//                     dp[i][j] = dp[i - 1][j - 1];
	//                     continue;
	//                 }

	//                 dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
	//             }
	//         }
	//         return dp[m][n] == 1;
	//     }
	/*20171121 1025*/
	/*TLE      1149*/
	//     bool isOneEditDistance(string s, string t) {
	//         int m = s.size(), n = t.size();
	//         if (m - n > 1 || n - m > 1) return false;
	//         if (!m && !n) return false;
	//         if (!m || !n) return true;

	//         vector<vector<int>>dp(m + 1, vector<int>(n + 1, m + n));

	//         for (int i = 0; i <= m; i++) {
	//             for (int j = 0; j <= n; j++) {
	//                 if (!i) {
	//                     dp[i][j] = j;
	//                     continue;
	//                 }

	//                 if (!j) {
	//                     dp[i][j] = i;
	//                     continue;
	//                 }

	//                 if (s[i - 1] == t[j - 1]) {
	//                     dp[i][j] = dp[i - 1][j - 1];
	//                     continue;
	//                 }

	//                 dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
	//             }
	//         }
	//         return dp[m][n] == 1;
	//     }
};
