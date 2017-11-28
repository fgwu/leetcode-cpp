class Solution {
public:
	// Binary Search
	// AC 1354
	bool valid(vector<int>& nums, int m, long target) {
		int cnt = 1;
		long sum = 0;
		for(auto num: nums) {
			if (num > target) return false;
			if (sum + num > target) {
				sum = num;
				cnt++;
			} else {
				sum += num;
			}
		}

		return cnt <= m;
	}

	int splitArray(vector<int>& nums, int m) {
		long hi = 0, lo = 0;
		for (auto num: nums)
			hi += num;

		while (lo < hi) {
			long mid = lo + (hi - lo) / 2;
			if (valid(nums, m, mid))
				hi = mid;
			else
				lo = mid + 1;
		}

		return lo;
	}



	// try optimize
	//     int splitArray(vector<int>& nums, int m) {
	//         int n = nums.size();
	//         vector<vector<int>> dp (n, vector<int>(m + 1, INT_MAX));
	//         vector<int> partial(1, 0);
	//         for (auto num: nums)
	//             partial.push_back(partial.back() + num);

	//         for (int i = 0; i < n; i++) {
	//             for (int j = 1; j <= m; j++) {
	//                 if (j == 1) {
	//                     dp[i][j] = partial[i + 1] - partial[0];
	//                     continue;
	//                 }
	//                 for (int k = j - 2; k + 1 <= i; k++)
	//                     dp[i][j] = min(dp[i][j], max(dp[k][j - 1], partial[i + 1] - partial[k + 1]));
	//             }
	//         }

	//         return dp[n - 1][m];
	//     }



	/*20171125 1010*/
	/*AC 20171126 1129*/
	//     int splitArray(vector<int>& nums, int m) {
	//         int n = nums.size();
	//         vector<vector<int>> dp (n, vector<int>(m + 1, INT_MAX));
	//         vector<vector<int>> subsum (n, vector<int>(n, -1));

	//         for (int i = 0; i < n; i++) {
	//             for (int j = 1; j <= m; j++) {
	//                 if (j == 1) {
	//                     if (i == 0)
	//                         subsum[0][i] = nums[0];
	//                     else
	//                         subsum[0][i] = subsum[0][i - 1] + nums[i];
	//                     dp[i][j] = subsum[0][i];
	//                 } else {
	//                     for (int k = j - 2; k + 1 <= i; k++) {
	//                         if (subsum[k + 1][i] < 0)
	//                             subsum[k + 1][i] = subsum[k][i] - nums[k];
	//                         dp[i][j] = min(dp[i][j], max(dp[k][j - 1], subsum[k + 1][i]));
	//                     }
	//                 }
	//             }
	//         }

	//         return dp[n - 1][m];
	//     }
};
