class Solution {
public:
	/*20170929 1100*/
	/*AC       1123*/
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (!obstacleGrid.size() || !obstacleGrid[0].size()) return 0;
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();

		vector<vector<int>> dp(m, vector<int>(n,0));

		for(int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (obstacleGrid[i][j]) {
					dp[i][j] = 0;
					continue;
				}

				if (!i && !j) {
					dp[i][j] = 1;
					continue;
				}

				dp[i][j] = (i? dp[i - 1][j]:0) +
					(j? dp[i][j - 1]:0);
			}
		}
		return dp[m - 1][n - 1];
	}
};
