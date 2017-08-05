class Solution {
public:
	/*20170804 0209*/
	/*AC       0226*/
	int search(vector<int>& nums, int target) {
		if (!nums.size()) return -1;
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			if (target == nums[m]) return m;
			if (nums[m] <= nums[r] && nums[m] >= nums[l]) {
				if (target < nums[m])
					r = m - 1;
				else
					l = m + 1;
			} else if (nums[m] >= nums[r] && nums[m] >= nums[l]) {
				if (target >= nums[l] && target < nums[m])
					r = m - 1;
				else
					l = m + 1;
			} else if (nums[m] <= nums[r] && nums[m] <= nums[l]) {
				if (target > nums[m] && target <= nums[r])
					l = m + 1;
				else
					r = m - 1;
			} else {
				assert(0); // cannot happen.
			}
		}
		if (target == nums[l]) return l;
		return -1;
	}
};
