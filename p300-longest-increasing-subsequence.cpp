class Solution {
public:
	/* opt concise */
	int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if (!n) return 0;
		vector<int> ml; // ml[i] stores the smallest elem that has the max length
		for(int i = 0; i < n; i++){
			auto it = lower_bound(ml.begin(), ml.end(), nums[i]);
			if (it == ml.end())
				ml.push_back(nums[i]);
			else
				*it = nums[i];
		}
		return ml.size();
	}

	/*opt AC 2210*/
	//     int findMaxPrev(vector<int>& ml, int elem) {
	//         int l = 0, r = ml.size();
	//         while (l < r) {
	//             int m = r - (r - l)/2;
	//             if (ml[m] >= elem)
	//                 r = m - 1;
	//             else
	//                 l = m;
	//         }
	//         // update ml[l + 1] to the min possible elem
	//         ml[l + 1] = min(ml[l + 1], elem);
	//         return l + 1;
	//     }

	//     int lengthOfLIS(vector<int>& nums) {
	//         int n = nums.size();
	//         if (!n) return 0;
	//         int res = INT_MIN;
	//         vector<int> ml(n + 1, INT_MAX); // ml[i] stores the smallest elem that has the max length
	//         for(int i = 0; i < n; i++){
	//             int loc = findMaxPrev(ml, nums[i]);
	//             res = max(res, loc);
	//             printf("nums[%d]=%d, loc=%d\n", i, nums[i], loc);
	//         }
	//         return res;
	//     }

	/*20170723 2056*/
	/*AC       2127*/
	//     int findMaxPrev(vector<int>& nums, vector<int>& l, int curr) {
	//         int cand = -1;
	//         for (int i = curr - 1; i >= 0; i--) {
	//             if (nums[i] >= nums[curr]) continue;
	//             if (cand < 0 || l[cand] < l[i]) cand = i;
	//         }
	//         return cand;
	//     }

	//     int lengthOfLIS(vector<int>& nums) {
	//         int n = nums.size();
	//         if (!n) return 0;
	//         int res = INT_MIN;
	//         vector<int> l(n, 0);
	//         for(int i = 0; i < n; i++){
	//             int loc = findMaxPrev(nums, l, i);
	//             if (loc < 0)
	//                 l[i] = 1;
	//             else
	//                 l[i] = l[loc] + 1;
	//             res = max(res, l[i]);
	//             // printf("nums[%d]=%d, l[%d]=%d\n", i, nums[i], i, l[i]);
	//         }
	//         return res;
	//     }
};
