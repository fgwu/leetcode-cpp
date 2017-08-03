class Solution {
public:
	/*20170730 2049*/
	/*AC       2206*/
	void setZeroes(vector<vector<int>>& matrix) {
		if (!matrix.size() || !matrix[0].size()) return;
		int m = matrix.size(), n = matrix[0].size(), row = -1, col = -1;

		for (int i = 0; i < m; i++){
			bool f = true;
			for (int j = 0; f && j < n; j++)
				f = matrix[i][j] != 0;
			if (f) {
				row = i;
				break;
			}
		}

		for (int j = 0; j < n; j++) {
			bool f = true;
			for (int i = 0; f && i < m; i++)
				f = matrix[i][j] != 0;
			if (f) {
				col = j;
				break;
			}
		}

		if (row == -1 || col == -1) {
			for (auto & r : matrix)
				r = vector<int>(n, 0);
			return;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++){
				if (i == row || j == col) continue;
				if (!matrix[i][j]) {
					matrix[i][col] = 0;
					matrix[row][j] = 0;
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == row || j == col) continue;
				if (!matrix[i][col] || !matrix[row][j])
					matrix[i][j] = 0;
			}
		}
	}
};
