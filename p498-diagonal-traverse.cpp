class Solution {
public:
	/*20170523 1711*/
	/*AC       1734*/
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (!matrix.size() || !matrix[0].size()) return res;
		int m = matrix.size(), n = matrix[0].size();
		for (int k = 0; k < m + n - 1; k++) {
			if ( !(k%2) ) // left -> right
				for (int j = 0; j <= k && j < n; j++) {
					int i = k - j;
					if (i < 0 || i >= m) continue;
					res.push_back(matrix[i][j]);
				}
			else
				for (int i = 0; i <= k && i < m; i++) {
					int j = k - i;
					if (j < 0 || j >= n) continue;
					res.push_back(matrix[i][j]);
				}
		}
		return res;
	}
};
