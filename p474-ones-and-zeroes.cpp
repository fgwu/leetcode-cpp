class Solution {
public:

	/*AC 0008*/
	int findMaxForm(vector<string>& strs, int m, int n) {
		if (!strs.size()) return 0;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= strs.size(); i++) {
			vector<vector<int>> nextdp(m + 1, vector<int>(n + 1, 0));
			for (int j = 0; j <= m; j++) {
				for (int k = 0; k <= n; k++) {
					int cnt0 = 0, cnt1 = 0;
					for (char c : strs[i - 1]) {
						if (c == '0')
							cnt0++;
						else
							cnt1++;
					}
					if (cnt0 > j || cnt1 > k)
						nextdp[j][k] = dp[j][k];
					else
						nextdp[j][k] = max(dp[j][k], 1 + dp[j - cnt0][k - cnt1]);
					// printf("dp[%d %d %d] = %d\n", i, j, k, dp[i][j][k]);
				}
			}
			swap(dp, nextdp);
		}

		return dp[m][n];
	}



	//     /*MLE 00:05*/
	//     int findMaxForm(vector<string>& strs, int m, int n) {
	//         if (!strs.size()) return 0;
	//         vector<vector<vector<int>>> dp(strs.size() + 1,
	//                                        vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
	//         for (int i = 1; i <= strs.size(); i++) {
	//             for (int j = 0; j <= m; j++) {
	//                 for (int k = 0; k <= n; k++) {
	//                     int cnt0 = 0, cnt1 = 0;
	//                     for (char c : strs[i - 1]) {
	//                         if (c == '0')
	//                             cnt0++;
	//                         else
	//                             cnt1++;
	//                     }
	//                     if (cnt0 > j || cnt1 > k)
	//                         dp[i][j][k] = dp[i - 1][j][k];
	//                     else
	//                         dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - cnt0][k - cnt1]);
	//                     // printf("dp[%d %d %d] = %d\n", i, j, k, dp[i][j][k]);
	//                 }
	//             }
	//         }

	//         return dp[strs.size()][m][n];
	//     }

	/*20170924 2037*/
	/*TLE      2116*/
	//     void helper(vector<string>& strs, int m, int n, int idx, int cnt, int &res){
	//         if (idx >= strs.size()) {
	//             res = max(res, cnt);
	//             return;
	//         }
	//         helper(strs, m, n, idx + 1, cnt, res);
	//         for (char c: strs[idx]) {
	//             if (c == '0')
	//                 m--;
	//             else
	//                 n--;
	//         }

	//         if (m < 0 || n < 0) return;
	//         helper(strs, m, n, idx + 1, cnt + 1, res);
	//     }

	//     int findMaxForm(vector<string>& strs, int m, int n) {
	//         int res = 0;
	//         helper(strs, m, n, 0, 0, res);
	//         return res;
	//     }
};
