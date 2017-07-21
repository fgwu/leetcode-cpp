class Solution {
public:
	/* remove tmp*/
	int uniquePaths(int m, int n) {
		if (m > n) return uniquePaths(n, m);
		vector<int> t(n, 1);
		for (int i = 1; i < m; i++)
			for (int j = 1; j < n; j++)
				t[j] += t[j - 1];
		return t[n - 1];
	}



	/*less space */
	/*AC 1502*/
	// int uniquePaths(int m, int n) {
	//     if (m > n) return uniquePaths(n, m);
	//     vector<int> t(n, 1);
	//     for (int i = 1; i < m; i++) {
	//         int tmp = 1;
	//         for (int j = 1; j < n; j++) {
	//             t[j] = tmp + t[j];
	//             tmp = t[j];
	//         }
	//     }
	//     return t[n - 1];
	// }


	/*20170719 1438*/
	/*AC       1451*/
	// int uniquePaths(int m, int n) {
	//     vector<vector<int>> t(m, vector<int>(n, 1));
	//     for (int i = 1; i < m; i++)
	//         for (int j = 1; j < n; j++)
	//             t[i][j] = t[i - 1][j] + t[i][j - 1];
	//     return t[m - 1][n - 1];
	// }
};
