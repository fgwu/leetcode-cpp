class Solution {
public:
	/*20170814 2313*/
	/*AC       2328*/
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (!matrix.size() || !matrix[0].size()) return res;
		int m = matrix.size(), n = matrix[0].size();

		for (int k = 0; k <= m - 1 - k && k <= n - 1 - k; k++) {
			if (k == m - 1 - k) { // single row
				for (int j = k; j <= n - 1 - k; j++)
					res.push_back(matrix[k][j]);
				return res;
			}
			if (k == n - 1 - k) { // single colomn
				for (int i = k; i <= m - 1 - k; i++)
					res.push_back(matrix[i][k]);
				return res;
			}

			for (int j = k; j < n - 1 - k; j++)
				res.push_back(matrix[k][j]);

			for (int i = k; i < m - 1 - k; i++)
				res.push_back(matrix[i][n - k - 1]);

			for (int j = n - 1 - k; j > k; j--)
				res.push_back(matrix[m - 1 - k][j]);

			for (int i = m - 1 - k; i > k; i--)
				res.push_back(matrix[i][k]);
		}

		return res;
	}
};
