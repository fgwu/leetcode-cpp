class Solution {
public:
	/*AC 2207*/
	int my_lower_bound(vector<int>& nums, int target) {
		if (!nums.size())  return 0;
		int lo = 0, hi = nums.size() - 1;
		while(lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] >= target)
				hi = mid;
			else
				lo = mid + 1;
		}
		if (nums[lo] >= target) return lo;
		return lo + 1;
	}

	int my_upper_bound(vector<int>& nums, int target) {
		if (!nums.size()) return 0;
		int lo = 0, hi = nums.size() - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (nums[mid] <= target)
				lo = mid + 1;
			else
				hi = mid;
		}
		if (nums[lo] <= target) return lo + 1;
		return lo;
	}

	vector<int> searchRange(vector<int>& nums, int target) {
		int lower = my_lower_bound(nums, target);
		int upper = my_upper_bound(nums, target);

		if (upper - 1 < lower) return vector<int>{-1, -1};
		return vector<int>{lower, upper-1};
	}


	//     /*20170809 2150*/
	//     /*AC       2157*/
	//     vector<int> searchRange(vector<int>& nums, int target) {
	//         int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
	//         int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

	//         if (upper - 1 < lower) return vector<int>{-1, -1};
	//         return vector<int>{lower, upper-1};
	//     }
};
