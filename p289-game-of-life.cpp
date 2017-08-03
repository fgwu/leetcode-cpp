class Solution {
public:
	/*20170725 2300*/
	/*20170726 1250*/
	/*AC       1310*/
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size();
		if (!m) return;
		int n = board[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int cnt = 0;
				cnt += (i - 1) >= 0 && (j - 1) >= 0 ? board[i - 1][j - 1] % 2 : 0;
				cnt += (i - 1) >= 0                 ? board[i - 1][j    ] % 2 : 0;
				cnt += (i - 1) >= 0 && (j + 1) <  n ? board[i - 1][j + 1] % 2 : 0;
				cnt +=                 (j - 1) >= 0 ? board[i    ][j - 1] % 2 : 0;
				cnt +=                 (j + 1) <  n ? board[i    ][j + 1] % 2 : 0;
				cnt += (i + 1) <  m && (j - 1) >= 0 ? board[i + 1][j - 1] % 2 : 0;
				cnt += (i + 1) <  m                 ? board[i + 1][j    ] % 2 : 0;
				cnt += (i + 1) <  m && (j + 1) <  n ? board[i + 1][j + 1] % 2 : 0;

				if (board[i][j]) {
					if (cnt == 2 || cnt == 3)
						board[i][j] += 2; // live
				} else { // dead cell
					if (cnt == 3)
						board[i][j] += 2;
				}
			}
		}

		for (auto & row: board)
			for (auto & cell: row)
				cell /= 2;

	}
};
