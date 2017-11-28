class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		int n = nums.size();
		vector<pair<int, int>> onesum(n); // max and the start idx
		vector<pair<int, int>> twosum(n); // max and the second idx
		vector<pair<int, int>> threesum(n); // max and the third idx

		for (int i = 0, partial = 0; i < n; i++) {
			partial += nums[i];
			if (i == k - 1) {
				onesum[i] = make_pair(partial, i);
			}else if (i > k - 1) {
				if (partial > onesum[i - 1].first)
					onesum[i] = make_pair(partial, i);
				else
					onesum[i] = onesum[i - 1];
			}

			if (i == 2 * k - 1) {
				twosum[i] = make_pair(partial + onesum[i - k].first, i);
			} else if (i > 2 * k - 1) {
				if (partial + onesum[i - k].first > twosum[i - 1].first)
					twosum[i] = make_pair(partial + onesum[i - k].first, i);
				else
					twosum[i] = twosum[i - 1];
			}

			if (i == 3 * k - 1) {
				threesum[i] = make_pair(partial + twosum[i - k].first, i);
			} else if (i > 2 * k - 1) {
				if (partial + twosum[i - k].first > threesum[i - 1].first)
					threesum[i] = make_pair(partial + twosum[i - k].first, i);
				else
					threesum[i] = threesum[i - 1];
			}

			if (i >= k - 1)
				partial -= nums[i - k + 1];
		}

		int i3 = threesum[n - 1].second;
		int i2 = twosum[i3 - k].second;
		int i1 = onesum[i2 - k].second;
		return vector<int>{i1 - k + 1, i2 - k + 1, i3 - k + 1};
	}

	/*20171124 1122*/
	/*AC     2237*/
	//     vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
	//         int n = nums.size();
	//         vector<pair<int, int>> onesum(n); // max and the start idx
	//         vector<pair<int, int>> twosum(n); // max and the second idx
	//         vector<pair<int, int>> threesum(n); // max and the third idx

	//         for (int i = 0, partial = 0; i < n; i++) {
	//             partial += nums[i];
	//             if (i == k - 1) {
	//                 onesum[i] = make_pair(partial, i);
	//             }else if (i > k - 1) {
	//                 if (partial > onesum[i - 1].first)
	//                     onesum[i] = make_pair(partial, i);
	//                 else
	//                     onesum[i] = onesum[i - 1];
	//             }
	//             if (i >= k - 1)
	//                 partial -= nums[i - k + 1];
	//         }

	//         for (int i = 0, partial = 0; i < n; i++) {
	//             partial += nums[i];
	//             if (i == 2 * k - 1) {
	//                 twosum[i] = make_pair(partial + onesum[i - k].first, i);
	//             } else if (i > 2 * k - 1) {
	//                 if (partial + onesum[i - k].first > twosum[i - 1].first)
	//                     twosum[i] = make_pair(partial + onesum[i - k].first, i);
	//                 else
	//                     twosum[i] = twosum[i - 1];
	//             }
	//             if (i >= k - 1)
	//                 partial -= nums[i - k + 1];
	//         }

	//         for (int i = 0, partial = 0; i < n; i++) {
	//             partial += nums[i];
	//             if (i == 3 * k - 1) {
	//                 threesum[i] = make_pair(partial + twosum[i - k].first, i);
	//             } else if (i > 2 * k - 1) {
	//                 if (partial + twosum[i - k].first > threesum[i - 1].first)
	//                     threesum[i] = make_pair(partial + twosum[i - k].first, i);
	//                 else
	//                     threesum[i] = threesum[i - 1];
	//             }
	//             if (i >= k - 1)
	//                 partial -= nums[i - k + 1];
	//         }

	//         int i3 = threesum[n - 1].second;
	//         int i2 = twosum[i3 - k].second;
	//         int i1 = onesum[i2 - k].second;
	//         return vector<int>{i1 - k + 1, i2 - k + 1, i3 - k + 1};
	//     }
};
