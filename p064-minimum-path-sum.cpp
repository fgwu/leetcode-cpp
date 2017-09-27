class Solution {
public:
	/*AC 1939 no extra space. but destroy the input matrix */
	int minPathSum(vector<vector<int>>& grid) {
		if (!grid.size() || !grid[0].size()) return 0;
		int m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!i && !j)
					continue;

				if (!i) {
					grid[i][j] = grid[i][j - 1] + grid[i][j];
					continue;
				}

				if (!j) {
					grid[i][j] = grid[i - 1][j] + grid[i][j];
					continue;
				}

				grid[i][j] = min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
			}
		}
		return grid[m - 1][n - 1];
	}

	/*20170925 1927*/
	/*AC       1936*/
	//     int minPathSum(vector<vector<int>>& grid) {
	//         if (!grid.size() || !grid[0].size()) return 0;
	//         int m = grid.size(), n = grid[0].size();
	//         vector<vector<int>> memo(m, vector<int>(n, 0));
	//         for (int i = 0; i < m; i++) {
	//             for (int j = 0; j < n; j++) {
	//                 if (!i && !j)  {
	//                     memo[i][j] = grid[i][j];
	//                     continue;
	//                 }

	//                 if (!i) {
	//                     memo[i][j] = memo[i][j - 1] + grid[i][j];
	//                     continue;
	//                 }

	//                 if (!j) {
	//                     memo[i][j] = memo[i - 1][j] + grid[i][j];
	//                     continue;
	//                 }

	//                 memo[i][j] = min(memo[i][j - 1], memo[i - 1][j]) + grid[i][j];
	//             }
	//         }
	//         return memo[m - 1][n - 1];
	//     }
};
