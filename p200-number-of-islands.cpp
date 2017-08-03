class Solution {
public:
	/* 20170802 2150 */
	/* AC       2202*/
	void expand(vector<vector<char>>& grid, int i, int j) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
		if (grid[i][j] == '0' || grid[i][j] == '2') return;
		grid[i][j] = '2';
		expand(grid, i - 1, j);
		expand(grid, i, j - 1);
		expand(grid, i + 1, j);
		expand(grid, i, j + 1);
	}


	int numIslands(vector<vector<char>>& grid) {
		if (!grid.size() || !grid[0].size()) return 0;
		int m = grid.size(), n = grid[0].size();

		int res = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// grid[i][j] = 0 water, 2 visited.
				if (grid[i][j] == '0' || grid[i][j] == '2' ) continue;
				expand(grid, i, j);
				res++;
			}
		}
		return res;
	}
};
