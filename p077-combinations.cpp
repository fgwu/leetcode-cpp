class Solution {
public:
	/*20170929 2306*/
	/*AC       2335*/
	void helper (vector<int>& base, int start, int boundary, int k, int n, vector<vector<int>>&res) {
		if (start >= k) {
			res.push_back(vector<int>(base.begin(), base.begin() + k));
			return;
		}

		for (int j = boundary; j < n; j++) {
			swap(base[start], base[j]);
			helper(base, start + 1, j + 1, k, n, res);
			swap(base[start], base[j]);
		}
	}

	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> base;
		for (int i = 1; i <= n; i++)
			base.push_back(i);
		helper(base, 0, 0, k, n, res);

		return res;
	}
};
