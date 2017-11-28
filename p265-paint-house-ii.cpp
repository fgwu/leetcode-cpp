class Solution {
public:

	/*O(k) space*/
	int minCostII(vector<vector<int>>& costs) {
		if (!costs.size() || !costs[0].size()) return 0;
		int n = costs.size(), k = costs[0].size();
		vector<int> dp(k);
		int min1, min2, min1_idx, last_min1, last_min2, last_min1_idx;
		for (int i = 0; i < n; i++) {
			min1 = min2 = INT_MAX;
			for (int j = 0; j < k; j++) {
				if (!i)
					dp[j] = costs[i][j];
				else
					dp[j] = (j == last_min1_idx? last_min2: last_min1) + costs[i][j];

				if (dp[j] < min1) {
					min2 = min1;
					min1 = dp[j];
					min1_idx = j;
				} else if (dp[j] < min2){
					min2 = dp[j];
				}
			}
			last_min1 = min1;
			last_min2 = min2;
			last_min1_idx = min1_idx;
		}

		return last_min1;
	}

	/*try O(nk)*/
	//     int minCostII(vector<vector<int>>& costs) {
	//         if (!costs.size() || !costs[0].size()) return 0;
	//         int n = costs.size(), k = costs[0].size();
	//         vector<vector<int>> dp(n, vector<int>(k));
	//         int min1, min2, min1_idx, last_min1, last_min2, last_min1_idx;
	//         for (int i = 0; i < n; i++) {
	//             min1 = min2 = INT_MAX;
	//             for (int j = 0; j < k; j++) {
	//                 if (!i)
	//                     dp[i][j] = costs[i][j];
	//                 else
	//                     dp[i][j] = (j == last_min1_idx? last_min2: last_min1) + costs[i][j];

	//                 if (dp[i][j] < min1) {
	//                     min2 = min1;
	//                     min1 = dp[i][j];
	//                     min1_idx = j;
	//                 } else if (dp[i][j] < min2){
	//                     min2 = dp[i][j];
	//                 }
	//             }
	//             last_min1 = min1;
	//             last_min2 = min2;
	//             last_min1_idx = min1_idx;
	//             printf("      %3d%3d%3d\n", min1, min2, min1_idx);
	//         }

	//     int res = INT_MAX;
	//     for (int c = 0; c < k; c++)
	//         res = min(res, dp[n - 1][c]);
	//     return res;
	// }


	/*20171127 1126*/
	/*AC       1134*/
	//     int minCostII(vector<vector<int>>& costs) {
	//         if (!costs.size() || !costs[0].size()) return 0;
	//         int n = costs.size(), k = costs[0].size();
	//         vector<vector<int>> dp(n, vector<int>(k));

	//         for (int i = 0; i < n; i++) {
	//             for (int j = 0; j < k; j++) {
	//                 if (!i){
	//                     dp[i][j] = costs[i][j];
	//                     continue;
	//                 }
	//                 // all dp[i - 1][c]
	//                 dp[i][j] = INT_MAX;
	//                 for (int c = 0; c < k; c++) {
	//                     if (c == j) continue;
	//                     dp[i][j] = min(dp[i][j], dp[i - 1][c] + costs[i][j]);
	//                 }
	//             }
	//         }

	//         int res = INT_MAX;
	//         for (int c = 0; c < k; c++)
	//             res = min(res, dp[n - 1][c]);
	//         return res;
	//     }
};
