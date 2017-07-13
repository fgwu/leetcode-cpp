class Solution {
public:
	/*20170710 2225  LCS */
	/*AC       2242*/
	int minDistance(string word1, string word2) {
		int m = word1.size(), n = word2.size();
		vector<vector<int>> M(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <=n; j++)
				if (word1[i - 1] == word2[j - 1])
					M[i][j] = M[i - 1][j - 1] + 1;
		                else
					M[i][j] = max(M[i - 1][j], M[i][j - 1]);

		return m + n - M[m][n] * 2;
	}
};
