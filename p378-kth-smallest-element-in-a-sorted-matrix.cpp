class Solution {
public:
	/*opt*/
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		if (!matrix.size() || !matrix[0].size()) return 0;
		int m = matrix.size(), n = matrix[0].size();
		int lo = matrix[0][0], hi = matrix[m - 1][n - 1];

		// loop invariant: the target element is always
		// between [lo, hi], inclusive.
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			int cnt = 0, j = 0;
			for (int i = m - 1; i >= 0; i--) {
				for (; j < n; j++)
					if (matrix[i][j] > mid) break;
				cnt += j;
			}
			// cnt += upper_bound(v.begin(), v.end(), mid) - v.begin();
			if (cnt >= k) hi = mid;
			else lo = mid + 1;
		}
		return lo;
	}


	/*20170703 1141 Binary Search */
	/*AC       1213*/
	//     int kthSmallest(vector<vector<int>>& matrix, int k) {
	//         if (!matrix.size() || !matrix[0].size()) return 0;
	//         int m = matrix.size(), n = matrix[0].size();
	//         int lo = matrix[0][0], hi = matrix[m - 1][n - 1];

	//         // loop invariant: the target element is always
	//         // between [lo, hi], inclusive.
	//         while (lo < hi) {
	//             int mid = lo + (hi - lo) / 2;
	//             int cnt = 0;
	//             for (const auto v : matrix)
	//                 cnt += upper_bound(v.begin(), v.end(), mid) - v.begin();
	//             if (cnt >= k) hi = mid;
	//             else lo = mid + 1;
	//         }
	//         return lo;
	//     }



	/*20170701 1220*/
	/*20170702 1025 restart */
	/*AC       1055 brute force*/
	// int kthSmallest(vector<vector<int>>& matrix, int k) {
	//     if (!matrix.size() || !matrix[0].size()) return 0;
	//     int m = matrix.size();
	//     int n = matrix[0].size();
	//     //cout << m << n << '\n';
	//     vector<int> idv(m, 0);
	//     int last, cand;
	//     while(k--) {
	//         cand = -1;
	//         last = INT_MAX;
	//         for (int i = 0; i < m; i++) {
	//             //printf("i=%d, m=%d\n", i, m);
	//             if (idv[i] >= 0 && matrix[i][idv[i]] <= last) {
	//                 last = matrix[i][idv[i]];
	//                 cand = i;
	//             }
	//         }
	//         //printf("matrix[%d][%d] = %d\n", cand, idv[cand], matrix[cand][idv[cand]]);
	//         if(++idv[cand] == n) idv[cand] = -1;
	//     }
	//     return last;
	// }
};
