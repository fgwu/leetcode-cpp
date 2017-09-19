class Solution {
public:
	/*SQ 20170909 0102*/
	/*AC          0115*/
	/*DFS + Memoization. time O(mn), space O(mn)*/
	//     int dfs(vector<vector<int>>& matrix, vector<vector<int>>& h, int i, int j){
	//         if (h[i][j]) return h[i][j];
	//         int m = matrix.size(), n = matrix[0].size();
	//         h[i][j] = 1;
	//         if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
	//             h[i][j] = max(h[i][j], 1 + dfs(matrix, h, i - 1, j));
	//         if (i + 1 <  m && matrix[i + 1][j] > matrix[i][j])
	//             h[i][j] = max(h[i][j], 1 + dfs(matrix, h, i + 1, j));
	//         if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
	//             h[i][j] = max(h[i][j], 1 + dfs(matrix, h, i, j - 1));
	//         if (j + 1 <  n && matrix[i][j + 1] > matrix[i][j])
	//             h[i][j] = max(h[i][j], 1 + dfs(matrix, h, i, j + 1));
	//         return h[i][j];
	//     }

	//     int longestIncreasingPath(vector<vector<int>>& matrix) {
	//         if (!matrix.size() || !matrix[0].size()) return 0;
	//         int m = matrix.size(), n = matrix[0].size(), res = 0;
	//         vector<vector<int>> h(m, vector<int>(n, 0));

	//         for (int i = 0; i < m; i++)
	//             for (int j = 0; j < n; j++)
	//                 res = max(res, dfs(matrix, h, i, j));

	//         return res;
	//     }




	/*20170908*/
	/*AC  0909 0056*/
	/* time: O(log(mn))   space: O(mn)*/
	//     int longestIncreasingPath(vector<vector<int>>& matrix) {
	//         if (!matrix.size() || !matrix[0].size()) return 0;
	//         int m = matrix.size(), n = matrix[0].size(), res = 0;

	//         vector<vector<int>> h(m, vector<int>(n, 1));

	//         auto cmp = [](const tuple<int, int, int> p1, const tuple<int, int, int> p2){
	//             return get<2>(p1) < get<2>(p2);
	//         };
	//         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp);
	//         for (int i = 0; i < m; i++)
	//             for (int j = 0; j < n; j++)
	//                 pq.push(make_tuple(i, j, matrix[i][j]));

	//         while (!pq.empty()) {
	//             tuple<int, int, int> p = pq.top();
	//             pq.pop();
	//             int i = get<0>(p), j = get<1>(p);
	//             if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) h[i][j] = max(h[i][j], 1 + h[i - 1][j]);
	//             if (i + 1 <  m && matrix[i + 1][j] > matrix[i][j]) h[i][j] = max(h[i][j], 1 + h[i + 1][j]);
	//             if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) h[i][j] = max(h[i][j], 1 + h[i][j - 1]);
	//             if (j + 1 <  n && matrix[i][j + 1] > matrix[i][j]) h[i][j] = max(h[i][j], 1 + h[i][j + 1]);
	//             // cout << i << " " << j << " " << matrix[i][j] << " " << h[i][j] << "\n";

	//             res = max(res, h[i][j]);
	//         }
	//         return res;
	//     }

	/*2nd try with lambda function captures.*/
	/*AC   0122*/
	/**/
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (!matrix.size() || !matrix[0].size()) return 0;
		int m = matrix.size(), n = matrix[0].size(), res = 0;

		vector<vector<int>> h(m, vector<int>(n, 1));

		auto cmp = [&matrix](const pair<int, int> p1, const pair<int, int> p2){
			return matrix[p1.first][p1.second] < matrix[p2.first][p2.second];
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				pq.push(make_pair(i, j));

		while (!pq.empty()) {
			pair<int, int> p = pq.top();
			pq.pop();
			int i = p.first, j = p.second;
			if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) h[i][j] = max(h[i][j], 1 + h[i - 1][j]);
			if (i + 1 <  m && matrix[i + 1][j] > matrix[i][j]) h[i][j] = max(h[i][j], 1 + h[i + 1][j]);
			if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) h[i][j] = max(h[i][j], 1 + h[i][j - 1]);
			if (j + 1 <  n && matrix[i][j + 1] > matrix[i][j]) h[i][j] = max(h[i][j], 1 + h[i][j + 1]);
			// cout << i << " " << j << " " << matrix[i][j] << " " << h[i][j] << "\n";

			res = max(res, h[i][j]);
		}
		return res;
	}
};
