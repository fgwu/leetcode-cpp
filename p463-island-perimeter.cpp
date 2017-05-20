class Solution {
public:
	/*20170517 16:18*/
	/*20170517 16:30*/
	/*AC       16:31*/

	int islandPerimeter(vector<vector<int>>& grid) {
		int i, j, rv = 0;
		if (grid.size() == 0 || grid[0].size() == 0) return 0;

		for (i = 0; i < grid.size(); i++)
			for (j = 0; j < grid[0].size(); j++) {
				if (grid[i][j] == 0) continue;

				if ((i - 1 >= 0 && grid[i - 1][j] == 0) || (i-1 < 0))
					rv++;
				if ((j - 1 >= 0 && grid[i][j - 1] == 0) || (j - 1 < 0))
					rv++;
				if ((i + 1 < grid.size() && grid[i + 1][j] == 0) || (i + 1 >= grid.size()))
					rv++;
				if ((j + 1 < grid[0].size() && grid[i][j + 1] == 0) || (j + 1 >= grid[0].size()))
					rv++;
			}

		return rv;
	}
};
