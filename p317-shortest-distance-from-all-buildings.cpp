class Solution {
public:
	/*20171124 0825*/
	/*         0845*/
	/*AC       0908*/
	int shortestDistance(vector<vector<int>>& grid) {
		if (!grid.size() || !grid[0].size()) return -1;
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> accu (m, vector<int> (n, 0));
		vector<vector<int>> empty (m, vector<int> (n, 0));
		vector<pair<int, int>> buildings;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// printf("%5d", grid[i][j]);
				switch (grid[i][j]) {
				case 0: // empty
					accu[i][j] = 0;
					empty[i][j] = INT_MAX;
					break;
				case 1: // building
					accu[i][j] = INT_MAX;
					empty[i][j] = -1;
					buildings.push_back(make_pair(i, j));
					break;
				case 2: // obstacle
					accu[i][j] = INT_MAX;
					empty[i][j] = -1;
					break;
				default:
					assert(0);
				}
			}
			// printf("\n");
		}
		// printf("--\n");
		for (auto &p: buildings) {
			vector<vector<int>> tmp(empty);
			tmp[p.first][p.second] = 0;
			queue<pair<int, int>> q;
			q.push(p);
			while(!q.empty()) {
				int i = q.front().first;
				int j = q.front().second;
				q.pop();

				if (i - 1 >= 0 && tmp[i - 1][j] > tmp[i][j] + 1) {
					tmp[i - 1][j] = tmp[i][j] + 1;
					q.push(make_pair(i - 1, j));
				}

				if (i + 1 < m && tmp[i + 1][j] > tmp[i][j] + 1) {
					tmp[i + 1][j] = tmp[i][j] + 1;
					q.push(make_pair(i + 1, j));
				}

				if (j - 1 >= 0 && tmp[i][j - 1] > tmp[i][j] + 1) {
					tmp[i][j - 1] = tmp[i][j] + 1;
					q.push(make_pair(i, j - 1));
				}

				if (j + 1 < n && tmp[i][j + 1] > tmp[i][j] + 1) {
					tmp[i][j + 1] = tmp[i][j] + 1;
					q.push(make_pair(i, j + 1));
				}
			}

			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					// printf("%5d", tmp[i][j]);
					if (tmp[i][j] == -1 || tmp[i][j] == 0) continue;
					if (accu[i][j] == INT_MAX) continue;
					if (tmp[i][j] == INT_MAX)
						accu[i][j] = INT_MAX;
					else
						accu[i][j] += tmp[i][j];
				}
				// printf("\n");
			}
			// printf("--\n");
		}
		int mindist = INT_MAX;
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++) {
				// printf("%5d", accu[i][j]);
				mindist = min(mindist, accu[i][j]);
			}
			// printf("\n");
		}

		if (mindist == INT_MAX) return -1;
		return mindist;
	}
};
