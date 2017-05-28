class Solution {
public:
	/*divide and conquer*/
	/*AC 0027 so subtle...*/
	void helper(vector<int>& nums, int start, int end, int& res, int& pre, int& post, int& sum) {
		if (start == end - 1) {
			res = sum = pre = post = nums[start];
			// cout << start << " " << end << " " << res << " " << pre << " " << post << "\n";
			return;
		}
		int mid = (start + end) / 2;
		int res1, pre1, post1, res2, pre2, post2, sum1, sum2;
		helper(nums, start, mid, res1, pre1, post1, sum1);
		helper(nums, mid, end, res2, pre2, post2, sum2);
		res = max(max(res1, res2), post1 + pre2);
		pre = max(pre1, sum1 + max(pre2, 0));
		post = max(post2, sum2 + max(post1, 0));
		sum = sum1 + sum2;
		// cout << start << " " << end << " " << res << " " << pre << " " << post << "\n";
	}

	int maxSubArray(vector<int>& nums) {
		int res, pre, post, sum;
		helper(nums, 0, nums.size(), res, pre, post, sum);
		return res;
	}


	/*AC 20170527 2346*/
	// int maxSubArray(vector<int>& nums) {
	//     if (!nums.size()) return 0;
	//     int max_sum = nums[0], suffix_max = nums[0];
	//     for (int i = 1; i < nums.size(); i++) {
	//         if (suffix_max <= 0) suffix_max = 0;
	//         suffix_max += nums[i];
	//         max_sum = max(max_sum, suffix_max);
	//     }
	//     return max_sum;
	// }


	/*20170527 2335*/
	/*time excceed 2339. but space reduces to O(n)*/
	// int maxSubArray(vector<int>& nums) {
	//     if (!nums.size()) return 0;
	//     int max_sum = nums[0], last_max = nums[0];
	//     vector<int> m (nums.size() + 1, 0);
	//     int res = INT_MIN;
	//     for (int k = 0; k < nums.size() + 1; k++) {
	//         for (int i = 0; i < nums.size() + 1 - k; i++) {
	//             if (!k) { m[i] = 0; continue; }
	//             m[i] = m[i] + nums[i + k - 1];
	//             // cout << "m[" << i << ","<< i + k << "]=" << m[i][i + k] << ", ";
	//             // cout << "nums[" << (i + k) << "]=" << nums[i + k - 1] << "\n";

	//             res = max(res, m[i]);
	//         }
	//     }
	//     return res;
	// }

	/*20170527 2314*/
	/*Time Exceeded 2334 Space O(n^2)*/
	// int maxSubArray(vector<int>& nums) {
	//     if (!nums.size()) return 0;
	//     int max_sum = nums[0], last_max = nums[0];
	//     vector<vector<int>> m (nums.size() + 1, vector<int>(nums.size() + 1, 0));
	//     int res = INT_MIN;
	//     for (int k = 0; k < nums.size() + 1; k++) {
	//         for (int i = 0; i < nums.size(); i++) {
	//             if (!k) { m[i][i+k] = 0; continue; }
	//             if (i + k >= nums.size() + 1) break;
	//             m[i][i + k] = m[i][i + k -1] + nums[i + k - 1];
	//             // cout << "m[" << i << ","<< i + k << "]=" << m[i][i + k] << ", ";
	//             // cout << "nums[" << (i + k) << "]=" << nums[i + k - 1] << "\n";

	//             res = max(res, m[i][i + k]);
	//         }
	//     }
	//     return res;
	// }
};
