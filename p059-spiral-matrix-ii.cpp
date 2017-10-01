class Solution {
public:
	/*20170929 1144*/
	/*AC       2208*/
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));

		int num = 1;
		for (int i = 0; i < n / 2 ; i++) { // 2: [0, 1)  4 [0, 2);
			for (int j = i; j < n - i - 1; j++)
				res[i][j] = num++;
			for (int j = i; j < n - i - 1; j++)
				res[j][n - i - 1] = num++;
			for (int j = n - i - 1; j > i; j--)
				res[n - i - 1][j] = num++;
			for (int j = n - i - 1; j > i; j--)
				res[j][i] = num++;
		}

		if (n % 2) res[n / 2][n / 2] = n * n;

		return res;
	}
};
